const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const n = +input.shift();
const weights = input.map(Number).sort((a, b) => a - b);
let ans = 0;
weights.forEach((weight, idx) => {
  ans = Math.max(ans, weight * (weights.length - idx));
});
console.log(ans);
