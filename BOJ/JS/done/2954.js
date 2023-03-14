const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim();

const regExp = /[aeiou]p[aeiou]/g;
const ans = input.replace(regExp, (match) => match[0]);
console.log(ans);
