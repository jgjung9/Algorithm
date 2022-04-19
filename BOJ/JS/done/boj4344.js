const fs = require("fs");
let input = fs.readFileSync("./input.txt").toString().split("\n");

let C = input[0];
let testCase = [];

for (let i = 1; i < input.length; i++) {
  const arr = input[i].split(" ").map((item) => +item);
  const test = {
    N: arr[0],
    arr: arr.slice(1),
  };

  testCase.push(test);
}

function solution(C, testCase) {
  for (let i = 0; i < C; i++) {
    const n = testCase[i].N;
    const avg =
      testCase[i].arr.reduce((avg, value) => (avg += value), 0) /
      testCase[i].arr.length;

    let aboveAvg = 0;

    for (let j = 0; j < testCase[i].N; j++) {
      if (avg < Number(testCase[i].arr[j])) {
        aboveAvg++;
      }
    }
    let per = ((aboveAvg / n) * 100).toFixed(3);

    console.log(`${per}%`);
  }
}
solution(C, testCase);
