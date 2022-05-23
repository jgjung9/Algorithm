/**
 * https://www.acmicpc.net/problem/2609
 *
 * 최대공약수 최소공배수
 */

const fs = require('fs');
const input = fs
    .readFileSync('./input.txt')
    .toString()
    .trim()
    .split(' ')
    .map(Number);

function GCD(a, b) {
    if (b === 0) return a;
    return GCD(b, a % b);
}

function LCM(a, b) {
    return (a * b) / GCD(a, b);
}

console.log(GCD(input[0], input[1]));
console.log(LCM(input[0], input[1]));
