import * as fs from 'fs';
const input: string[] = fs
  .readFileSync('./input.txt')
  .toString()
  .trim()
  .split('\n');
const n: number = +input[0];
const honey: number[] = input[1].split(' ').map(Number);
const leftSum: number[] = Array(n);
const rightSum: number[] = Array(n);
(leftSum[0] = honey[0]), (rightSum[n - 1] = honey[n - 1]);
for (let i = 1; i < n; i++) {
  leftSum[i] = leftSum[i - 1] + honey[i];
}
for (let i = n - 2; i >= 0; i--) {
  rightSum[i] = rightSum[i + 1] + honey[i];
}
let ans: number = 0;
for (let i = 1; i < n - 1; i++) {
  ans = Math.max(ans, leftSum[i] + rightSum[i] - honey[0] - honey[n - 1]);
}

for (let i = 1; i < n - 1; i++) {
  const res1: number = leftSum[n - 1] - leftSum[0] - honey[i];
  const res2: number = leftSum[n - 1] - leftSum[i];
  ans = Math.max(ans, res1 + res2);
}
for (let i = n - 2; i > 0; i--) {
  const res1: number = rightSum[0] - rightSum[n - 1] - honey[i];
  const res2: number = rightSum[0] - rightSum[i];
  ans = Math.max(ans, res1 + res2);
}
console.log(ans);
