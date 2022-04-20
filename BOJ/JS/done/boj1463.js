const fs = require("fs");
const input = +fs.readFileSync("./input.txt").toString();

// f(n) = 1 + f(n/2) or 1 + f(3/n) or 1 + f(n-1) 중 최소
const answer = [0, 0, 1, 1];

for (let i = 4; i <= input; i++) {
  const result = [];
  const remainThree = i % 3;
  const remainTwo = i % 2;

  if (remainThree === 0) {
    result.push(1 + answer[i / 3]);
  }
  if (remainTwo === 0) {
    result.push(1 + answer[i / 2]);
  }
  result.push(1 + answer[i - 1]);

  const min = Math.min(...result);
  answer.push(min);
}
console.log(answer[input]);
