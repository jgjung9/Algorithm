/**
 * https://www.acmicpc.net/problem/9576
 *
 * solution: 그리디 알고리즘
 */
const fs = require('fs');
let input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const t = +input.shift();
const ans = [];

for (let i = 0; i < t; i++) {
  const [n, m] = input[0].split(' ').map(Number);
  const books = Array(n + 1).fill(false);
  const students = input
    .slice(1, m + 1)
    .map((item) => {
      return item.split(' ').map(Number);
    })
    .sort((a, b) => {
      if (a[0] < b[0]) return -1;
      if (a[0] === b[0] && a[1] < b[1]) return -1;
      else return 1;
    });

  let cnt = 0;
  for (let i = m - 1; i >= 0; i--) {
    const [a, b] = students[i];
    for (let j = b; j >= a; j--) {
      if (!books[j]) {
        books[j] = true;
        cnt++;
        break;
      }
    }
  }
  ans.push(cnt);
  input = input.slice(m + 1);
}

console.log(ans.join('\n'));
