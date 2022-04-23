function solution(n) {
  let i;
  for (i = 0; i * i < n; i++) {}
  if (i * i === n) {
    return (i + 1) * (i + 1);
  }
  return -1;
}
