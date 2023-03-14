const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim();

const regExp = /U([A-Za-z\s]{0,})C([A-Za-z\s]{0,})P([A-Za-z\s]{0,})C/g;

if (regExp.test(input)) {
  console.log(`I love UCPC`);
} else {
  console.log(`I hate UCPC`);
}
