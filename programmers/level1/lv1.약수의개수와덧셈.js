function countDivisor(n) {
  if (n === 1) return 1;

  let count = 1;
  for (let i = 1; i <= Math.floor(n / 2); i++) {
    if (n % i === 0) {
      count++;
    }
  }

  return count;
}

function solution(left, right) {
  let answer = 0;

  for (let i = left; i <= right; i++) {
    countDivisor(i) % 2 === 0 ? (answer += i) : (answer -= i);
  }

  return answer;
}

solution(24, 27);
