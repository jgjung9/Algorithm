const fs = require("fs");
let input = fs.readFileSync("./input.txt").toString().split("\r\n");

const N = input[0].split(" ").map((item) => +item)[0];
const M = input[0].split(" ").map((item) => +item)[1];

let board = [];
for (let i = 1; i < input.length; i++) {
  board.push(input[i].split(""));
}

const fristWhiteBoard = ["B", "W", "B", "W", "B", "W", "B", "W"];
const fristBlackBoard = ["W", "B", "W", "B", "W", "B", "W", "B"];

// 8 x 8 첫 시작이 White 인 경우 count
function FWCcheck(board) {
  let count = 0;

  for (let i = 0; i < 8; i++) {
    if (i % 2 === 0) {
      for (let j = 0; j < 8; j++) {
        if (board[i][j] === fristWhiteBoard[j]) count++;
      }
    } else {
      for (let j = 0; j < 8; j++) {
        if (board[i][j] === fristBlackBoard[j]) count++;
      }
    }
  }
  return count;
}

// 8 x 8 첫 시작이 Black 일 때 count
function FBCcheck(board) {
  let count = 0;

  for (let i = 0; i < 8; i++) {
    if (i % 2 === 0) {
      for (let j = 0; j < 8; j++) {
        if (board[i][j] === fristBlackBoard[j]) count++;
      }
    } else {
      for (let j = 0; j < 8; j++) {
        if (board[i][j] === fristWhiteBoard[j]) count++;
      }
    }
  }
  return count;
}

function changeCount(r, c, board) {
  let cutBoard = board.slice(r, r + 8);
  for (let i = 0; i < 8; i++) {
    cutBoard[i] = cutBoard[i].slice(c, c + 8);
  }

  let min = Math.min(FWCcheck(cutBoard), FBCcheck(cutBoard));
  return min;
}

function solution(N, M, board) {
  let min = 64;
  for (let r = 0; r <= N - 8; r++) {
    for (let c = 0; c <= M - 8; c++) {
      let temp = changeCount(r, c, board);
      if (temp < min) min = temp;
    }
  }
  console.log(min);
}

solution(N, M, board);
