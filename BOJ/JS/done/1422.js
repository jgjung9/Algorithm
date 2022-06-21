const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\r\n');
const [k, n] = input[0].split(' ').map(Number);
const num = input.slice(1);
const max = Math.max(...num);

function compare(a, b) {
  if (a + b > b + a) {
    return -1;
  } else {
    return 1;
  }
}

for (let i = 0; i < n - k; i++) {
  num.push(max.toString());
}

let ans = '';
num.sort(compare).forEach((n) => {
  ans += n;
});

console.log(ans);
