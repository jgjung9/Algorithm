const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const n = +input[0];
const distances = [];

for (let i = 2; i < input.length; i++) {
  distances.push(+input[i] - +input[i - 1]);
}

function GCD(a, b) {
  while (b > 0) {
    const temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}

const gcd = distances.reduce((pre, cur) => {
  pre = GCD(pre, cur);
  return pre;
}, distances[0]);

let ans = 0;
distances.forEach((distance) => {
  ans += distance / gcd - 1;
});
console.log(ans);
