/**
 * https://www.acmicpc.net/problem/10815
 *
 * Set을 통해 간단한 구현
 */
const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const N = +input[0];
const cardSet = new Set(input[1].split(' ').map(Number));
const M = +input[2];
const cards = input[3].split(' ').map(Number);
const answer = [];
cards.forEach((card) => {
    cardSet.has(card) ? answer.push(1) : answer.push(0);
});
console.log(answer.join(' '));
