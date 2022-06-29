function solution(numbers) {
  let answer = '';

  answer = numbers
    .map((v) => v.toString())
    .sort((a, b) => {
      if (`${a}${b}` > `${b}${a}`) return -1;
      if (`${a}${b}` == `${b}${a}`) return 0;
      if (`${a}${b}` < `${b}${a}`) return 1;
    })
    .join('');
  return +answer === 0 ? '0' : answer;
}

console.log(solution([3, 30, 34, 5, 9]));
