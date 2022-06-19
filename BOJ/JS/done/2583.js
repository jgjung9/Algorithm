const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const [m, n, k] = input[0].split(' ').map(Number);
const board = [];
const visited = [];
for (let i = 0; i < m; i++) {
  board.push(Array(n).fill(0));
  visited.push(Array(n).fill(false));
}

input.slice(1).forEach((coordinates) => {
  const [x1, y1, x2, y2] = coordinates.split(' ').map(Number);
  for (let y = y1; y < y2; y++) {
    for (let x = x1; x < x2; x++) {
      board[y][x] = 1;
    }
  }
});

const dy = [0, 0, -1, 1];
const dx = [-1, 1, 0, 0];

function DFS(y, x) {
  visited[y][x] = true;
  let area = 1;
  for (let dir = 0; dir < 4; dir++) {
    const nextY = y + dy[dir];
    const nextX = x + dx[dir];
    if (nextY < 0 || nextY >= m) continue;
    if (nextX < 0 || nextX >= n) continue;
    if (visited[nextY][nextX]) continue;
    if (board[nextY][nextX]) continue;
    area += DFS(nextY, nextX);
  }
  return area;
}

let cnt = 0;
const area = [];
for (let y = 0; y < m; y++) {
  for (let x = 0; x < n; x++) {
    if (board[y][x] == 0 && visited[y][x] == false) {
      area.push(DFS(y, x));
      cnt++;
    }
  }
}

console.log(cnt);
console.log(area.sort((a, b) => a - b).join(' '));
