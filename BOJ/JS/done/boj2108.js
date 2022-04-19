const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().trim().split("\n");
const N = +input.shift();
const arr = input.map(Number).sort((a, b) => a - b);

const avg = Math.round(arr.reduce((avg, value) => (avg += value), 0) / N) || 0;
const center = arr[Math.floor(N / 2)];
const range = Math.max(...arr) - Math.min(...arr);
const countMap = new Map();

arr.forEach((value) => {
  countMap.has(value)
    ? countMap.set(value, countMap.get(value) + 1)
    : countMap.set(value, 1);
});

const max = Math.max(...countMap.values());
const maxCountArr = [];
countMap.forEach((value, key) => {
  if (value === max) {
    maxCountArr.push(key);
  }
});
maxCountArr.sort((a, b) => a - b);

const mode = maxCountArr.length === 1 ? maxCountArr[0] : maxCountArr[1];

console.log(avg);
console.log(center);
console.log(mode);
console.log(range);
