const fs = require('fs');
const [n, m] = fs
  .readFileSync('./input.txt')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

const C = [];
for (let i = 0; i <= 100; i++) {
  const row = Array(101).fill(0);
  C.push(row);
}

for (let i = 1; i <= n; i++) {
  C[i][0] = C[i][i] = 1;
  C[i][1] = i;
}

for (let i = 2; i <= n; i++) {
  for (let j = 2; j <= m; j++) {
    if (j > i) break;
    C[i][j] = BigInt(C[i - 1][j - 1]) + BigInt(C[i - 1][j]);
  }
}

console.log(C[n][m].toString());
