function solution(brown, yellow) {
  var answer = [];
  const area = brown + yellow;
  for (let h = 3; h <= area / 3; h++) {
    if (area % h !== 0) continue;
    const w = area / h;
    const yh = h - 2;
    const yw = w - 2;
    const yArea = yh * yw;
    if (yArea === yellow) {
      w >= h ? answer.push(w, h) : answer.push(h, w);
      break;
    }
  }

  return answer;
}

solution(10, 2);
