const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const k = +input[0];
const oper = input[1].split(' ');
const visited = Array(10).fill(false);
const selected = [];
let ansMax = Number.MIN_SAFE_INTEGER,
  ansMin = Number.MAX_SAFE_INTEGER;

function check(cur, idx) {
  if (oper[idx] === '<' && selected[idx] < cur) return true;
  if (oper[idx] === '>' && selected[idx] > cur) return true;
  return false;
}

function go(k, idx) {
  if (k + 1 === idx) {
    ansMax = Math.max(ansMax, Number(selected.join('')));
    ansMin = Math.min(ansMin, Number(selected.join('')));
    return;
  }

  for (let i = 0; i < 10; i++) {
    if (visited[i]) continue;
    if (idx > 0 && !check(i, idx - 1)) continue;
    visited[i] = true;
    selected.push(i);
    go(k, idx + 1);
    visited[i] = false;
    selected.pop();
  }
}

go(k, 0);
ansMax =
  ansMax.toString().length > k ? ansMax.toString() : '0' + ansMax.toString();
ansMin =
  ansMin.toString().length > k ? ansMin.toString() : '0' + ansMin.toString();
console.log(ansMax);
console.log(ansMin);
