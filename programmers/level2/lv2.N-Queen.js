// true 보드에 퀸이 놓여진 곳
const board = [];
for (let i = 0; i < 12; i++) {
  const row = Array(12).fill(false);
  board.push(row);
}

const dx = [-1, -1, 1, 1];
const dy = [-1, 1, -1, 1];
function check(x, y, n) {
  for (let i = 0; i < n; i++) {
    if (board[i][y]) return false;
  }
  for (let dir = 0; dir < 4; dir++) {
    let nextX = x;
    let nextY = y;
    while (true) {
      nextX += dx[dir];
      nextY += dy[dir];
      if (nextX < 0 || nextX >= n) break;
      if (nextY < 0 || nextY >= n) break;
      if (board[nextX][nextY]) return false;
    }
  }
  return true;
}

function NQueen(n, x = 0) {
  if (n === x) {
    return 1;
  }

  let cnt = 0;
  for (let i = 0; i < n; i++) {
    if (!check(x, i, n)) continue;
    board[x][i] = true;
    cnt += NQueen(n, x + 1);
    board[x][i] = false;
  }
  return cnt;
}

function solution(n) {
  let answer = 0;
  answer = NQueen(n);
  return answer;
}

console.log(solution(12));
