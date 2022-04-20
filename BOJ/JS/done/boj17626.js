const fs = require("fs");
const input = +fs.readFileSync("./input.txt").toString();

// answer, answer[n] = f(n), f = square 들의 합의 최소값
const answer = [0, 1, 2];

for (let i = 3; i <= input; i++) {
  // f(n) = 1 + f(n-k^2) 중 최소 값
  const result = [];
  for (let j = 1; j * j <= i; j++) {
    const square = j * j;
    square === i ? result.push(1) : result.push(answer[i - square] + 1);
  }
  answer.push(Math.min(...result));
}

console.log(answer[input]);
