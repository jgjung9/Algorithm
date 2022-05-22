/**
 * https://www.acmicpc.net/problem/7576
 *
 * hint: BFS를 이용해 탐색을 시작하고 깊이를 저장한다
 * 초기 값이 1인 점을 BFS를 통해 탐색한다
 * Queue에 들어가 있는 점들을 BFS 통해 탐색한다.
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');

// row : N  column : M
const [M, N] = input[0].split(' ').map(Number);
const board = [];
input.slice(1).forEach((row) => {
    board.push(row.split(' ').map(Number));
});

// left 0, down 1, right 2, up 3, row : x, column : y
const dx = [0, 1, 0, -1];
const dy = [-1, 0, 1, 0];
const depths = [];
const visited = [];
const found = [];
const queue = [];
let front = 0;
let rear = 0;
for (let i = 0; i < N; i++) {
    depths.push(Array(M).fill(-1));
    visited.push(Array(M).fill(false));
    found.push(Array(M).fill(false));
}
function Bfs(x, y, depth) {
    if (board[x][y] === -1) return;
    if (visited[x][y]) return;
    visited[x][y] = true;
    if (depths[x][y] === -1) depths[x][y] = depth;

    for (let dir = 0; dir < 4; dir++) {
        const nextX = x + dx[dir];
        const nextY = y + dy[dir];
        if (nextX < 0 || nextX >= N) continue;
        if (nextY < 0 || nextY >= M) continue;
        if (board[nextX][nextY] === -1) continue;
        if (found[nextX][nextY]) continue;
        found[nextX][nextY] = true;
        queue.push([nextX, nextY, depth + 1]);
        rear++;
    }
}

// 이미 완료되어 있는 상태면 done: true
let done;
let cnt = 0;
for (let x = 0; x < N; x++) {
    for (let y = 0; y < M; y++) {
        if (board[x][y] === 0) {
            cnt++;
        }
    }
}
cnt > 0 ? (done = false) : (done = true);

if (done) {
    console.log(0);
} else {
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            if (board[i][j] === 1) Bfs(i, j, 0);
        }
    }
    while (front !== rear) {
        const start = front;
        const end = rear;
        for (let i = start; i < end; i++) {
            const [nextX, nextY, depth] = queue[i];
            Bfs(nextX, nextY, depth);
            front++;
        }
    }
    let max = Number.MIN_SAFE_INTEGER;
    let changedCnt = 0;
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            if (depths[i][j] > 0) changedCnt++;
            if (depths[i][j] > max) max = depths[i][j];
        }
    }

    if (changedCnt === cnt) {
        console.log(max);
    } else console.log(-1);
}

