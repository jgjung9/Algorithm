const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim();

const regExp = /(pi)|(ka)|(chu)/g;

if (input.replace(regExp, '') === '') {
  console.log('YES');
} else {
  console.log('NO');
}
