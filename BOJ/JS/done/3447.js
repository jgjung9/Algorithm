const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim();

const regExp = /BUG/g;
let ans = input;

while (regExp.test(ans)) {
  ans = ans.replace(regExp, '');
}

console.log(ans);
