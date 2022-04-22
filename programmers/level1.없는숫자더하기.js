function solution(numbers) {
  const number = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

  for (let x of numbers) {
    number[x] = 0;
  }

  return number.reduce((sum, cur) => (sum += cur), 0);
}

console.log(solution([1, 2, 3, 4, 6, 7, 8, 0]));

// [1,2,3,4,6,7,8,0]	14
// [5,8,4,0,6,7,9]	6
