function dencimalToThree(n) {
  let answer = [];

  while (n > 0) {
    answer.push(n % 3);
    n = Math.floor(n / 3);
  }

  return answer.reverse().join("");
}

function threeToDencimal(n) {
  let sum = 0;

  n = n.toString();
  for (let i = 0; i < n.length; i++) {
    sum += n[n.length - i - 1] * Math.pow(3, i);
  }

  return sum;
}

function solution(n) {
  n = dencimalToThree(n).split("").reverse().join("");
  return threeToDencimal(n);
}

console.log(solution(45));
