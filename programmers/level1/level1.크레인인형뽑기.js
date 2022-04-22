function pickUp(board, moves) {
  const result = [];

  for (let x of moves) {
    for (let i = 0; i < board.length; i++) {
      if (board[i][x - 1] === 0) {
        continue;
      }
      result.push(board[i][x - 1]);
      board[i][x - 1] = 0;
      break;
    }
  }

  return result;
}

function solution(board, moves) {
  let answer = [];
  let count = 0;
  const result = pickUp(board, moves);

  for (let x of result) {
    if (answer === []) {
      answer.push(x);
    }

    if (answer[answer.length - 1] === x) {
      answer.pop();
      count += 2;
    } else {
      answer.push(x);
    }
  }

  return count;
}

solution(
  [
    [0, 0, 0, 0, 0],
    [0, 0, 1, 0, 3],
    [0, 2, 5, 0, 1],
    [4, 2, 4, 4, 2],
    [3, 5, 1, 3, 1],
  ],
  [1, 5, 3, 5, 1, 2, 1, 4]
);

// [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]	[1,5,3,5,1,2,1,4]	4
