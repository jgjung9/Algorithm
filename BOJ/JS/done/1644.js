/**
 * https://www.acmicpc.net/problem/1644
 *
 * solution: 아리스토테네스의 체를 활용한 소수 판정
 */
const fs = require('fs');
const n = +fs.readFileSync('./input.txt').toString().trim();
const prime = [];
const visited = Array(n + 1).fill(false);

for (let i = 2; i <= n; i++) {
  if (visited[i]) continue;
  prime.push(i);
  for (let j = i + i; j <= n; j += i) {
    visited[j] = true;
  }
}
let cnt = 0;
for (let i = 0; i < prime.length; i++) {
  let sum = 0;
  for (let j = i; j < prime.length; j++) {
    sum += prime[j];
    if (sum === n) cnt++;
    else if (sum > n) break;
  }
}
console.log(cnt);
