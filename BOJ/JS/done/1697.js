/**
 * https://www.acmicpc.net/problem/1697
 *
 * hint: BFS 통해 탐색을 진행하여
 * 해당 노드를 발견한 부모노드를 찾아서 카운트하여 반환한다.
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim();
const [N, K] = input.split(' ').map(Number);

const queue = [];
let front = 0;
let rear = 0;

const parent = [];
const visited = [];
const found = [];
const dx = [-1, 1, 2];

function Bfs(vetex) {
    if (visited[vetex] == true) return;
    visited[vetex] = true;

    for (let dir = 0; dir < 3; dir++) {
        const posX = dir < 2 ? vetex + dx[dir] : vetex * dx[dir];
        if (posX < 0 || posX > 100000) continue;
        if (found[posX] === true) continue;
        found[posX] = true;
        parent[posX] = vetex;
        queue.push(posX);
        rear++;
    }
}

parent[N] = N;
found[N] = true;
Bfs(N);
while (front !== rear) {
    if (queue[front] === K) break;
    Bfs(queue[front++]);
}

let count = 0;
let pos = K;
while (parent[pos] != pos) {
    count++;
    pos = parent[pos];
}

console.log(count);
