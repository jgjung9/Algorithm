function solution(arr) {
  let avg = arr.reduce((sum, cur) => (sum += cur), 0) / arr.length;
  return avg;
}
