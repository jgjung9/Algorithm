const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().split("\n");

const L = input.shift();
const str = input
  .shift()
  .split("")
  .map((value) => value.charCodeAt(0) - "a".charCodeAt(0) + 1);

function solution(str) {
  let result = str;

  for (let i = 0; i < result.length; i++) {
    for (let j = 1; j <= i; j++) {
      result[i] *= 31;
      result[i] %= 1234567891;
    }
  }

  result = result.reduce((avg, value) => (avg += value), 0) % 1234567891;
  console.log(result);
}

solution(str);
