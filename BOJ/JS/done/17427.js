/**
 * https://www.acmicpc.net/problem/17427
 *
 * hint: 1 <= i <= N 일 때,
 * 1 ~ N 까지 모든 약수들중에 i가 등장하는 횟수는 N / i 의 몫이다.
 */

const fs = require('fs');
const N = +fs.readFileSync('./input.txt').toString().trim();

let answer = 0;
for (let i = 1; i <= N; i++) {
    answer += i * Math.floor(N / i);
}

console.log(answer);
