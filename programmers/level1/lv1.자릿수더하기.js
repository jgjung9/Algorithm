function solution(n) {
  let answer = n
    .toString()
    .split("")
    .map(Number)
    .reduce((sum, cur) => (sum += cur), 0);
  return answer;
}
