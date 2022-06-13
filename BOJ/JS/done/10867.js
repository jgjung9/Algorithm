const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const numbers = new Set(input[1].split(' ').map(Number));
const ans = [...numbers].sort((a, b) => a - b);
console.log(ans.join(' '));
