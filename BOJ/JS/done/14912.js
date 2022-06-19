const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split(' ');
const [n, d] = input;
let ans = 0;

function freq(n, d) {
  let cnt = 0;
  for (let i = 0; i < n.length; i++) {
    cnt = n[i] === d ? cnt + 1 : cnt;
  }
  return cnt;
}

for (let i = 1; i <= n; i++) {
  ans += freq(i.toString(), d);
}

console.log(ans);
