const fs = require('fs');
const input = fs
  .readFileSync('./input.txt')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

function countTen(n) {
  let cnt = 0;
  for (let i = 5; i <= n; i *= 5) {
    cnt += Math.floor(n / i);
  }
  return cnt;
}

const ans = [];
input.forEach((value) => {
  if (value >= 5) ans.push(countTen(value));
});

ans.forEach((v, idx) => {
  console.log(`Case #${idx + 1}: ${v}`);
});
