function isPrime(n) {
  let answer = true;

  for (let i = 2; i * i <= n; i++) {
    if (n % i === 0) {
      answer = false;
      break;
    }
  }

  return answer;
}

function solution(nums) {
  let count = 0;

  for (let i = 0; i < nums.length - 2; i++) {
    for (let j = i + 1; j < nums.length - 1; j++) {
      for (let k = j + 1; k < nums.length; k++) {
        const sum = nums[i] + nums[j] + nums[k];
        if (isPrime(sum)) {
          count++;
        }
      }
    }
  }

  return count;
}

console.log(solution([1, 2, 7, 6, 4]));

// [1,2,3,4]	1
// [1,2,7,6,4]	4
