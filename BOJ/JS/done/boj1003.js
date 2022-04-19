const fs = require("fs");
const input = fs
  .readFileSync("./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map(Number);
const T = input.shift();
const result = [];

for (let i = 0; i <= 40; i++) {
  const obj = {
    0: 0,
    1: 0,
  };
  if (i === 0) {
    obj[0] = 1;
    result.push(obj);
  } else if (i === 1) {
    obj[1] = 1;
    result.push(obj);
  } else {
    obj[0] = result[i - 1][0] + result[i - 2][0];
    obj[1] = result[i - 1][1] + result[i - 2][1];
    result.push(obj);
  }
}

input.forEach((value) => {
  console.log(result[value][0], result[value][1]);
});
