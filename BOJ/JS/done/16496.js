const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const n = +input[0];
const num = input[1].split(' ').sort((a, b) => {
  if (a + b > b + a) {
    return -1;
  } else {
    return 1;
  }
});

if (num[0] === '0') {
  console.log(0);
} else {
  console.log(num.join(''));
}
