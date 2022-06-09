const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim();
const result = input.split('d2').join('');
const result2 = input.split('D2').join('');

if (result.length < input.length || result2.length < input.length)
  console.log('D2');
else console.log('unrated');
