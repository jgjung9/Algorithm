const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const [n, score, p] = input[0].split(' ').map(Number);
let scores = n === 0 ? [] : input[1].split(' ').map(Number);
let ans;

scores.sort((a, b) => b - a);
if (scores.length < p) {
  scores.push(score);
  scores.sort((a, b) => b - a);
  ans = scores.indexOf(score) + 1;
} else {
  if (scores[p - 1] < score) {
    scores.push(score);
    scores.sort((a, b) => b - a);
    ans = scores.indexOf(score) + 1;
  } else ans = -1;
}

console.log(ans);
