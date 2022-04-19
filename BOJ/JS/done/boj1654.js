const fs = require("fs");
let input = fs.readFileSync("./input.txt").toString().split("\r\n");

const [K, N] = input.shift().split(" ");
input = input.map((v) => +v);

function solution(K, N, input) {
  let start = 0;
  let end = input.sort((a, b) => b - a)[0];
  let mid = Math.floor((start + end) / 2);

  while (start !== end) {
    let count = 0;
    for (let i = 0; i < K; i++) {
      count += Math.floor(input[i] / mid);
    }

    if (count >= N) {
      start = mid;
      mid = Math.floor((start + end) / 2);
      if (start === mid) {
        mid += 1;
      }
    } else {
      end = mid - 1;
      mid = Math.floor((start + end) / 2);
    }
  }
  console.log(end);
}

solution(K, N, input);
