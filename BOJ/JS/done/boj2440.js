const fs = require("fs");
const input = fs
  .readFileSync("./input.txt")
  .toString()
  .split()
  .map((v) => +v);

let result = [];
for (let i = 0; i < input; i++) {
  let str = "";
  for (let j = 0; j < input - i; j++) {
    str += "*";
  }
  result.push(str);
}

console.log(result.join("\n"));
