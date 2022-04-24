function solution(a, b) {
  const start = Math.min(a, b);
  const end = Math.max(a, b);
  const n = end - start + 1;
  return (n * (end + start)) / 2;
}
