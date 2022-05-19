const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const N = +input.shift();
const time = input
    .toString()
    .split(' ')
    .map(Number)
    .sort((a, b) => a - b);

let result = 0;
for (let i = 0; i < N; i++) {
    let sum = 0;
    for (let j = 0; j <= i; j++) {
        sum += time[j];
    }
    result += sum;
}
console.log(result);
