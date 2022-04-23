function solution(d, budget) {
  let count = 0;

  d.sort((a, b) => b - a);

  while (true) {
    if (d.length < 1) {
      break;
    }

    budget -= d.pop();
    if (budget < 0) {
      break;
    }
    count++;
  }

  return count;
}

solution([1, 3, 2, 5, 4], 9);

// [1,3,2,5,4]	9	3
// [2,2,3,3]	10	4
