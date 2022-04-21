// a + 2b + 3c = n 이 되는 모든 (a, b, c)  순서쌍의 개수를 구하는 것으로 생각할 수 있음
// 1 + 1 + 2 / 1 + 2 + 1 을 다른 것으로 취급하므로 순서가 존재
// a b c 가 정해 졌을 때 순열의 개수는 (a + b + c)! / a!b!c!
const fs = require("fs");
const input = fs
  .readFileSync("./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map(Number);
const T = +input.shift();

function factorial(n) {
  if (n === 0 || n === 1) {
    return 1;
  }

  let result = 1;
  for (let i = 1; i <= n; i++) {
    result *= i;
  }

  return result;
}

// 순서쌍의 수를 계산하는 함수
function pairCount(n) {
  let a, b, c;
  let count = 0;

  for (a = 0; a <= n; a++) {
    for (b = 0; 2 * b <= n; b++) {
      for (c = 0; 3 * c <= n; c++) {
        if (a + 2 * b + 3 * c === n) {
          count +=
            factorial(a + b + c) / (factorial(a) * factorial(b) * factorial(c)); // (a + b + c)! / a!b!c!;
        }
      }
    }
  }

  return count;
}

function solution(input) {
  for (let x of input) {
    console.log(pairCount(x));
  }
}

solution(input);
