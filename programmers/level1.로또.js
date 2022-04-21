function rank(n) {
  switch (n) {
    case 6:
      return 1;
    case 5:
      return 2;
    case 4:
      return 3;
    case 3:
      return 4;
    case 2:
      return 5;
    default:
      return 6;
  }
}

function solution(lottos, win_nums) {
  let answer = [];
  const myLotto = new Set(lottos);
  const winLotto = new Set(win_nums);

  let zeroCount = 0;
  for (let x of lottos) {
    if (x === 0) {
      zeroCount++;
    }
  }

  let maxCount = zeroCount;
  let count = 0;

  for (let x of myLotto) {
    if (winLotto.has(x)) {
      count++;
    }
  }
  maxCount += count;

  answer.push(rank(maxCount));
  answer.push(rank(count));
  return answer;
}

console.log(solution([0, 0, 0, 0, 0, 0], [38, 19, 20, 40, 15, 25]));

// [44, 1, 0, 0, 31, 25]	[31, 10, 45, 1, 6, 19]	[3, 5]
// [0, 0, 0, 0, 0, 0]	[38, 19, 20, 40, 15, 25]	[1, 6]
// [45, 4, 35, 20, 3, 9]	[20, 9, 3, 45, 4, 35]	[1, 1]
