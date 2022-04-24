function GCD(n, m) {
  if (n > m) {
    return n % m === 0 ? m : GCD(m, n % m);
  } else {
    return m % n === 0 ? n : GCD(n, m % n);
  }
}

function LCM(n, m) {
  const gcd = GCD(n, m);
  return (n / gcd) * (m / gcd) * gcd;
}

function solution(n, m) {
  return [GCD(n, m), LCM(n, m)];
}
