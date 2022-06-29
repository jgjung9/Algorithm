/**
 * https://www.acmicpc.net/problem/9019
 *
 * solution: BFS
 * 각 지점에 도달하기 위해 발생한 command와 부모를 기록
 * target으로 부터 역추적하여 발생한 command를 찾고 출력
 */
const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const t = +input[0];
const com = ['D', 'S', 'L', 'R'];

const parent = Array(10000);
const command = Array(10000);

function BFS(node) {
  const queue = [];
  let front, rear;
  front = rear = 0;
  parent[node] = node;
  queue.push(node);
  rear++;

  while (front != rear) {
    node = queue[front++];
    for (let dir = 0; dir < 4; dir++) {
      let nextNode;
      if (dir == 0) nextNode = (node * 2) % 10000;
      else if (dir == 1) {
        nextNode = node - 1 < 0 ? 9999 : node - 1;
      } else if (dir == 2) {
        nextNode = (Math.floor(node / 1000) + node * 10) % 10000;
      } else {
        nextNode = Math.floor(node / 10) + (node % 10) * 1000;
      }
      if (parent[nextNode] !== -1) continue;
      parent[nextNode] = node;
      command[nextNode] = com[dir];
      queue.push(nextNode);
      rear++;
    }
  }
}

function returnCommand(target) {
  let ans = '';
  while (parent[target] != target) {
    ans = command[target] + ans;
    target = parent[target];
  }
  return ans;
}

const answer = [];
input.slice(1).forEach((v) => {
  const [start, target] = v.split(' ').map(Number);
  parent.fill(-1);
  command.fill(-1);
  BFS(start);
  answer.push(returnCommand(target));
});

console.log(answer.join('\n'));
