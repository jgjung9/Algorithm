const fs = require("fs");
let input = fs
  .readFileSync("./input.txt")
  .toString()
  .split(" ")
  .map((item) => +item);

function returnStar(i, j, input) {
  let n = Math.floor(input / 3);
  if (i < 3 && j < 3) {
    if (i === 1 && j === 1) return " ";
    else return "*";
  }

  if (Math.floor(i / n) === 1 && Math.floor(j / n) === 1) {
    return " ";
  } else {
    return returnStar(i % n, j % n, n);
  }
}

function solution(input) {
  let result = "";
  for (let i = 0; i < input; i++) {
    for (let j = 0; j < input; j++) {
      result += returnStar(i, j, input);
    }
    result += "\n";
  }
  console.log(result);
}

solution(input);
