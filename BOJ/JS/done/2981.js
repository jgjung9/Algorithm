/**
 * https://www.acmicpc.net/problem/2981
 *
 * hint: 입력받은 모든 수는 N1, N2, ... 은 N1 % M = N2 % M = ...
 * 을 만족하는 M이 존재한다. 위 조건이 성립하기식으로 풀어서 쓰면
 * N1 + M*n1 = N2 - M*n2 = N3 - M*n3 ... (ni = Ni를 M으로 나눴을 때 몫)
 * Ni - Nj = M*(ni - nj) 가 성립한다.
 * 따라서 임의의 입력받은 수 두 개의 차들은 공약수로 M을 가지게 된다.
 * 따라서 모든 값들의 차를 구하고 그들의 최대 공약수를 구하면 모든 공약수를 알 수 있고,
 * 이를 작은 수부터 나열하면 된다.
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const N = +input[0];
const numArr = input
    .slice(1)
    .map(Number)
    .sort((a, b) => a - b);

function GCD(a, b) {
    while (true) {
        if (b === 0) return a;
        const temp = a;
        a = b;
        b = temp % b;
    }
}

const diff = [];
const answer = [];

for (let i = 1; i < N; i++) {
    diff.push(numArr[i] - numArr[i - 1]);
}

let m = diff[1] ? GCD(diff[1], diff[0]) : diff[0];
for (let i = 2; i < diff.length; i++) {
    m = GCD(diff[i], m);
}

for (let i = 2; i * i <= m; i++) {
    if (i * i === m) answer.push(i);
    else if (m % i === 0) {
        answer.push(i);
        answer.push(m / i);
    }
}
answer.push(m);

console.log(answer.sort((a, b) => a - b).join(' '));
