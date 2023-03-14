const fs = require('fs');
const input = fs
  .readFileSync('./input.txt')
  .toString()
  .trim()
  .split('\n')
  .slice(1);

const regExp = /[0-9]+/g;
const result = [];
input.forEach((str) => {
  const matched = str.match(regExp);
  if (matched) result.push(matched);
});
result
  .flat(1)
  .map((v) => {
    const matched = v.match(/[1-9]/);
    return matched ? v.slice(matched.index) : '0';
  })
  .sort((a, b) => a - b)
  .forEach((v) => console.log(v));
