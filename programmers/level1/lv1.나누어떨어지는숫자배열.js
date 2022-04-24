function solution(arr, divisor) {
  let answer = [];
  for (const x of arr) {
    if (x % divisor === 0) answer.push(x);
  }

  return answer.length === 0 ? [-1] : answer.sort((a, b) => a - b);
}
