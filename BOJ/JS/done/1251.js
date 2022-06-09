/**
 * https://www.acmicpc.net/problem/1251
 *
 * solution: brute force
 * 최대 길이 50의 문자열이 주어지고 삼등분한다면 경우의 수는
 * 첫 번째 문자열의 마지막 문자와 두 번째 문자열의 마지막 문자를 고르는 경우의 수라고
 * 볼 수 있으므로 49C2의 경우의 수가 존재한다.
 * 대략 49 * 48 / 2 ~ 50 * 50 /2 => 약 12500가지의 경우가 존재한다.
 * 따라서 충분히 부르트포스를 통해 해결할 수 있는 시간복잡도를 가지게된다.
 */
const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('');
const ans = [];
const len = input.length;

for (let i = 0; i < len - 2; i++) {
  for (let j = i + 1; j < len - 1; j++) {
    const str =
      input
        .slice(0, i + 1)
        .reverse()
        .join('') +
      input
        .slice(i + 1, j + 1)
        .reverse()
        .join('') +
      input
        .slice(j + 1)
        .reverse()
        .join('');
    ans.push(str);
  }
}

ans.sort();
console.log(ans[0]);
