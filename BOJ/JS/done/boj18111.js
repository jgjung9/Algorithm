const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [N, M, B] = input.shift().split(" ").map(Number);
let board = [];

input.forEach((item) => board.push(item.split(" ").map(Number)));
board = board.flat();

const maxHeight = Math.max(...board);
const minHeight = Math.min(...board);
let minTime = Number.MAX_VALUE;
let height = maxHeight;

for (let i = maxHeight; i >= minHeight; i--) {
  let boxNum = B;
  let breakBox = 0;
  let fillBox = 0;
  let spendTime = 0;

  for (let j = 0; j < board.length; j++) {
    const diff = board[j] - i;
    diff > 0 ? (breakBox += diff) : (fillBox += diff * -1);
  }

  boxNum = B + breakBox;
  if (boxNum < fillBox) {
    continue;
  }

  spendTime = breakBox * 2 + fillBox;
  if (spendTime < minTime) {
    minTime = spendTime;
    height = i;
  }
}

console.log(minTime, height);
