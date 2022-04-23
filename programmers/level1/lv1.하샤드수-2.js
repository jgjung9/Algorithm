function solution(x) {
  let sum = x
    .toString()
    .split("")
    .reduce((pre, cur) => (pre += +cur), 0);

  if (x % sum === 0) {
    return true;
  }

  return false;
}
