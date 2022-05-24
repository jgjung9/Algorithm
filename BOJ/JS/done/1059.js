/**
 * https://www.acmicpc.net/problem/1059
 *
 * hint: n 보다 작은 값중에 최대값과
 * n 보다 큰 값중에 최소값을 구하고 그 값이 포함되지 않으면서
 * n을 포함하는 모든 구간을 구한다.
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const L = +input[0];
const set = input[1].split(' ').map(Number);
const n = +input[2];

const lessThanN = set.filter((v) => v < n);
const greaterThanN = set.filter((v) => v > n);

if (!lessThanN || !greaterThanN || set.includes(n)) console.log(0);
else {
    let min = Math.max(...lessThanN);
    const max = Math.min(...greaterThanN);
    if (min < 0) min = 0;
    const left = n - min;
    const right = max - n;

    const answer = left * right - 1;
    console.log(answer);
}
