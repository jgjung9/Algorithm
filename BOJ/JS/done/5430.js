const fs = require('fs');
let input = fs.readFileSync('./input.txt').toString().trim().split('\r\n');
let t = +input.shift();
const ans = [];

function check(p, arr) {
  let rCnt = 0;
  let front = 0;
  let rear = arr.length - 1;
  for (let i = 0; i < p.length; i++) {
    if (p[i] === 'R') {
      rCnt++;
      continue;
    }
    if (front > rear) return 'error';

    if (rCnt % 2 === 0) front++;
    else rear--;
  }
  if (rCnt % 2 === 0) return `[${arr.slice(front, rear + 1).join(',')}]`;
  else
    return `[${arr
      .slice(front, rear + 1)
      .reverse()
      .join(',')}]`;
}

while (t--) {
  const p = input[0];
  const arr = input[2]
    .slice(1, input[2].length - 1)
    .split(',')
    .filter(Number);
  ans.push(check(p, arr));
  input = input.slice(3);
}

console.log(ans.join('\n'));
