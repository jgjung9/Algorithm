const fs = require("fs");
let input = fs.readFileSync("./input.txt").toString().split("-");

function solution(input) {
  let result = 0;
  result = input
    .shift()
    .split("+")
    .reduce((sum, value) => (sum += +value), 0);

  for (let x of input) {
    let value = x.split("+").reduce((sum, value) => (sum += +value), 0);
    result -= value;
  }

  console.log(result);
}

solution(input);
