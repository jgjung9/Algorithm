const fs = require("fs");
let input = fs.readFileSync("./input.txt").toString().split("\n");
const now = input[0].split(" ").map((item) => +item);

const needTime = +input[1];

function solution(now, needTime) {
  let time = [now[0], now[1] + needTime];
  if (time[1] >= 60) {
    time[0] += Math.floor(time[1] / 60);
    time[0] %= 24;
    time[1] %= 60;
  }
  console.log(time.join(" "));
}

solution(now, needTime);
