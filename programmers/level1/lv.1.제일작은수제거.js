function solution(arr) {
  let index = 0,
    min = Number.MAX_SAFE_INTEGER;

  arr.forEach((value, idx) => {
    if (value < min) {
      index = idx;
      min = value;
    }
  });

  arr.splice(index, 1);
  return arr.length === 0 ? [-1] : arr;
}
