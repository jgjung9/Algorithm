const fs = require("fs");
let input = fs.readFileSync("./input.txt").toString().split("\n");

function solution(input) {
  let result = "";
  for (let str of input) {
    result += str + "\n";
  }
  console.log(result);
}

solution(input);
