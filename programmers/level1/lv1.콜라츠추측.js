function solution(num) {
  let count = 0;

  while (num > 1) {
    if (count > 500) {
      break;
    }

    if (num % 2 === 0) {
      num /= 2;
      count++;
      continue;
    }

    if (num % 2 === 1) {
      num = num * 3 + 1;
      count++;
    }
  }

  return count > 500 ? -1 : count;
}

solution(16);
