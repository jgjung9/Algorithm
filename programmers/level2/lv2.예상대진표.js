function fight(a, b) {
  if (a % 2 !== 1 || b % 2 !== 0) return false;
  if (a !== b - 1) return false;
  return true;
}

function solution(n, a, b) {
  let round = 1;
  if (a > b) {
    const temp = a;
    a = b;
    b = temp;
  }
  while (!fight(a, b)) {
    a = Math.floor((a + 1) / 2);
    b = Math.floor((b + 1) / 2);
    round++;
  }
  return round;
}
