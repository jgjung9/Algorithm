const fs = require("fs");
let input = fs
  .readFileSync("./input.txt")
  .toString()
  .split(" ")
  .map((item) => +item);

function solution(input) {
  let equal = new Set(input);
  let max = 0;
  for (let element of equal) {
    let count = 0;
    let result = 0;
    for (let i = 0; i < input.length; i++) {
      if (element === input[i]) count++;
    }
    if (count === 1) {
      result = element * 100;
    } else if (count === 2) {
      result = 1000 + element * 100;
    } else {
      result = element * 1000 + 10000;
    }

    if (max < result) max = result;
  }

  console.log(max);
}

solution(input);
