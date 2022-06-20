const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const n = +input[0];
let budgets = input[1]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);
let money = +input[2];
let ans;

for (let i = 0; i < n; i++) {
  if (budgets[i] * (n - i) <= money) {
    ans = budgets[i];
    money -= ans;
    continue;
  }
  ans = Math.floor(money / (n - i));
  break;
}

console.log(ans);
