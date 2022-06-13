const fs = require('fs');
const input = fs
  .readFileSync('./input.txt')
  .toString()
  .trim()
  .split('\n')
  .map((v) => v.toLowerCase());
const aeiou = 'aeiou';

for (let i = 0; i < input.length; i++) {
  if (input[i] === '#') break;
  let ans = 0;
  for (let j = 0; j < input[i].length; j++) {
    if (aeiou.includes(input[i][j])) ans++;
  }
  console.log(ans);
}
