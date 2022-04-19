const fs = require("fs");
let input = fs.readFileSync("./input.txt").toString();

function solution(input) {
  let result = [];

  while (input.length >= 10) {
    result.push(input.slice(0, 10));
    input = input.slice(10);
  }
  result.push(input);

  console.log(result.join("\n"));
}

solution(input);
