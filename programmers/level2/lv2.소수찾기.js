const isPrime = Array(1e7).fill(true);
isPrime[0] = isPrime[1] = false;

for (let i = 2; i * i <= isPrime.length; i++) {
  if (isPrime[i]) {
    for (let j = i + i; j < isPrime.length; j += i) {
      isPrime[j] = false;
    }
  }
}

function solution(numbers) {
  var answer = 0;
  const candidates = new Set();
  const visited = Array(numbers.length).fill(false);

  function makeCandidate(len = 0, number = '') {
    if (len > 0) candidates.add(+number);
    if (len === numbers.length) return;

    for (let i = 0; i < numbers.length; i++) {
      if (visited[i]) continue;
      visited[i] = true;
      number += numbers[i];
      makeCandidate(len + 1, number);
      number = number.slice(0, number.length - 1);
      visited[i] = false;
    }
  }

  makeCandidate();
  candidates.forEach((v) => {
    if (isPrime[v]) answer++;
  });

  return answer;
}
console.log(solution('17'));
