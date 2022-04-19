const fs = require("fs");
let input = fs.readFileSync("./input.txt").toString();
input = +input;

function solution(input) {
  console.log(input - 543);
}

solution(input);
