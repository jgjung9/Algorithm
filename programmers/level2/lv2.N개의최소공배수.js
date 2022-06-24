function GCD(a, b) {
  while (b > 0) {
    const temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}

function LCM(a, b) {
  return (a * b) / GCD(a, b);
}

function solution(arr) {
  let lcm = 1;
  arr.forEach((v) => {
    lcm = LCM(lcm, v);
  });

  return lcm;
}

console.log(solution([1, 2, 3]));
