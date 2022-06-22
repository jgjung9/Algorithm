const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const t = +input[0];
const ropes = input.slice(1);
const ans = [];
const isPrime = Array(1.5e6).fill(true);
const prime = [];
isPrime[0] = isPrime[1] = false;

for (let i = 2; i * i < isPrime.length; i++) {
  for (let j = i + i; j < isPrime.length; j += i) {
    isPrime[j] = false;
  }
}
isPrime.forEach((b, idx) => {
  if (b) prime.push(idx);
});

function check(a, b) {
  const sum = a + b;
  if (a + b === 2) return false;
  if ((a + b) % 2 === 0) return true;
  if (sum - 2 < isPrime.length) return isPrime[sum - 2];
  for (let i = 0; i < prime.length; i++) {
    if ((sum - 2) % prime[i] === 0) return false;
  }
  return true;
}

ropes.forEach((v) => {
  const [a, b] = v.split(' ').map(Number);
  check(a, b) ? ans.push('YES') : ans.push('NO');
});

console.log(ans.join('\n'));
