const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().split("\r\n");
const [N, M] = input.shift().split(" ").map(Number);
const poketmonList = input.splice(0, N);

const poketmonDic = new Map();
for (let i = 0; i < N; i++) {
  if (!poketmonDic.has(poketmonList[i])) {
    poketmonDic.set(poketmonList[i], i + 1);
    poketmonDic.set(`${i + 1}`, poketmonList[i]);
  }
}

for (let i = 0; i < M; i++) {
  console.log(poketmonDic.get(input[i]));
}
