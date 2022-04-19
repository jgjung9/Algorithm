const input = +"93"; //+prompt();

function solution(n) {
  let temp = Math.floor(n / 10);
  let remain = n % 10;
  if (temp === 0) {
    if (remain >= 3 && 6 > remain) {
      return 1;
    } else if (remain >= 6 && 9 > remain) {
      return 2;
    } else {
      return 3;
    }
  }

  return solution(temp) * solution(remain);
}

console.log(solution(input));
