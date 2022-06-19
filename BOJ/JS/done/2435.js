const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const [n, k] = input[0].split(' ').map(Number);
const temperatures = input[1].split(' ').map(Number);
const sum = [...temperatures];

for (let i = 1; i < n; i++) {
  sum[i] += sum[i - 1];
}

const res = [sum[k - 1]];
for (let i = k; i < n; i++) {
  res.push(sum[i] - sum[i - k]);
}

const ans = Math.max(...res);
console.log(ans);
