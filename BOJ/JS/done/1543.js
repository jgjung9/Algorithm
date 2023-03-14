const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');

const regExp = new RegExp(input[1], 'g');
const result = input[0].match(regExp);
console.log(result ? result.length : 0);
