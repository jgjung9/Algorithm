const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().split(" ");

function GCD(a, b) {
  if (a % b === 0) {
    return b;
  } else {
    return GCD(b, a % b);
  }
}

function LCM(a, b) {
  return (a * b) / GCD(a, b);
}

function solution(input) {
  const gcd = GCD(input[0], input[1]);
  const lcm = LCM(input[0], input[1]);

  console.log(gcd);
  console.log(lcm);
}

solution(input);
