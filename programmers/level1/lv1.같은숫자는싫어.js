function solution(arr) {
  let pre = arr[0];
  let answer = [pre];

  for (const x of arr) {
    if (x === pre) {
      continue;
    }

    pre = x;
    answer.push(pre);
  }

  return answer;
}
