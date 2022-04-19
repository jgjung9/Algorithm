const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().split("\r\n");

const [N, Nlist, M, Mlist] = input.map((v) => v.split(" ").map((v) => +v));

function solution(Nlist, Mlist) {
  const set = new Set(Nlist);
  const result = Mlist.map((v) => (set.has(v) ? 1 : 0));
  console.log(result.join("\n"));
}

solution(Nlist, Mlist);
