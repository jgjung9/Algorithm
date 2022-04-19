function primeNumber(n) {
  let bool = true;
  if (n === 2) return bool;
  for (let i = 2; i * i <= n; i++) {
    if (n % i === 0) {
      bool = false;
      break;
    }
  }
  return bool;
}

function goldbachConjecture(n) {
  let answer = [];
  let num1 = 2;
  let num2 = n - 2;
  for (let i = 2; i <= n / 2; i++) {
    if (primeNumber(num1) && primeNumber(num2)) {
      answer.push([num1, num2]);
    }
    num1++;
    num2--;
  }
  return answer;
}

console.log(goldbachConjecture(100));
