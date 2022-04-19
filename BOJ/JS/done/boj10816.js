const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().split("\r\n");

const [N, M] = [+input[0], +input[2]];
const arrN = input[1].split(" ").map((v) => +v);
const arrM = input[3].split(" ").map((v) => +v);

const resultObj = {};
for (let i = 0; i < arrN.length; i++) {
  resultObj[arrN[i]] === undefined
    ? (resultObj[arrN[i]] = 1)
    : resultObj[arrN[i]]++;
}

let result = "";

for (let i = 0; i < arrM.length; i++) {
  resultObj[arrM[i]] === undefined
    ? (result += 0)
    : (result += resultObj[arrM[i]]);

  result += " ";
}

console.log(result.trim());
