const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim();

const regExp = /[A-Z][a-z]{0,}/g;
const result = input.match(regExp);
let mod = 0;
let ans = 0;

result.forEach((command) => {
  mod = command.length % 4;
  ans += mod && 4 - mod;
});

ans -= mod && 4 - mod;
console.log(ans);
