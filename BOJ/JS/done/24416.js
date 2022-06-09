const fs = require('fs');
const n = +fs.readFileSync('./input.txt').toString().trim();

let recursive = 0;
let dp = 0;
const f = Array(n);
function fiboRecursive(n) {
  if (n == 1 || n == 2) {
    recursive++;
    return 1;
  } else return fiboRecursive(n - 1) + fiboRecursive(n - 2);
}

function fiboDp(n) {
  f[0] = f[1] = 1;
  for (let i = 2; i < n; i++) {
    dp++;
    f[i] = f[i - 1] + f[i - 2];
  }
}

fiboRecursive(n);
fiboDp(n);

console.log(`${recursive} ${dp}`);
