function solution(x, n) {
  let answer = [];
  let temp = x;
  for (let i = 0; i < n; i++) {
    answer.push(temp);
    temp += x;
  }
  return answer;
}
