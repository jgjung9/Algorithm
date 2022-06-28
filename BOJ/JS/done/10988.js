const fs = require('fs');
const word = fs.readFileSync('./input.txt').toString().trim();

let ok = true;
for (let i = 0; i <= word.length / 2; i++) {
  if (word[i] != word[word.length - 1 - i]) {
    ok = false;
    break;
  }
}

ok ? console.log(1) : console.log(0);
