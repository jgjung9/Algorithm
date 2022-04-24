function solution(numbers) {
  const set = new Set();
  for (let i = 0; i < numbers.length - 1; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      set.add(numbers[i] + numbers[j]);
    }
  }
  const answer = [...set];

  return answer.sort((a, b) => a - b);
}

console.log(solution([5, 0, 2, 7]));

// [2,1,3,4,1]	[2,3,4,5,6,7]
// [5,0,2,7]	[2,5,7,9,12]
