const fs = require("fs");
const input = fs
  .readFileSync("./input.txt")
  .toString()
  .split(" ")
  .map((v) => +v);

const [N, K] = input;

function solution(N, K) {
  let list = [];
  let result = [];
  let index = K - 1;

  for (let i = 1; i <= N; i++) {
    list.push(i);
  }

  while (list.length > 0) {
    result.push(list.splice(index, 1));
    result = result.flat();
    index += K - 1;
    index = index % list.length;
  }
  console.log(`<${result.join(", ")}>`);
}

solution(N, K);
