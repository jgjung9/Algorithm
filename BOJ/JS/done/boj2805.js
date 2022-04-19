const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().split("\n");
const [N, M] = input.shift().split(" ").map(Number);
const treeHeight = input.shift().split(" ").map(Number);

let start = 0;
let end = Math.max(...treeHeight);
let mid = Math.floor(end / 2);

while (start <= end) {
  const sum = treeHeight.reduce((avg, value) => {
    const diff = value - mid;
    return diff >= 0 ? (avg += diff) : (avg += 0);
  }, 0);

  if (sum > M) {
    start = mid + 1;
    mid = Math.floor((end + start) / 2);
  } else if (sum < M) {
    end = mid - 1;
    mid = Math.floor((end + start) / 2);
  } else {
    break;
  }
}

console.log(mid);
