const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().trim().split("\n");

const N = +input.shift();
const board = [];
input.forEach((item) => {
  board.push(item.split(" ").map(Number));
});

const whitePaper = [];
const bluePaper = [];

// arr의 값이 모두 값으면 true, 다른 경우 false
function check(arr) {
  let pre = arr[0];
  for (let x of arr) {
    if (x === pre) {
      pre = x;
    } else {
      return false;
    }
  }
  return true;
}

// 배열의 나누는 함수
function dividePaper(arr) {
  const leftTop = [];
  const leftBottom = [];
  const rightTop = [];
  const rightBottom = [];

  for (let i = 0; i < arr.length; i++) {
    const left = [];
    const right = [];
    for (let j = 0; j < arr.length; j++) {
      j < arr.length / 2 ? left.push(arr[i][j]) : right.push(arr[i][j]);
    }
    if (i < arr.length / 2) {
      leftTop.push(left);
      rightTop.push(right);
    } else {
      leftBottom.push(left);
      rightBottom.push(right);
    }
  }

  return [leftTop, leftBottom, rightTop, rightBottom];
}

const answer = [];

// 재귀적으로 배열 나눠서 최종적으로 남은 배열만이 하나의 색상 배열임
function solution(arr) {
  if (check(arr.flat())) {
    answer.push(arr);
  } else {
    let [a, b, c, d] = dividePaper(arr);
    solution(a);
    solution(b);
    solution(c);
    solution(d);
  }
}
solution(board);

for (let x of answer) {
  x[0][0] === 0 ? whitePaper.push(x) : bluePaper.push(x);
}

console.log(whitePaper.length);
console.log(bluePaper.length);
