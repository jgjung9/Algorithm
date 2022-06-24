function solution(s) {
  const elements = [];

  let str = '';
  s = s.slice(1, -1);
  for (let ch of s) {
    if (ch === '{') continue;
    if (ch === '}') {
      elements.push(
        str
          .split(',')
          .filter((v) => v !== '')
          .map(Number)
      );
      str = '';
    } else {
      str += ch;
    }
  }
  elements.sort((a, b) => a.length - b.length);
  const answer = [...new Set(elements.flat())];
  return answer;
}

solution('{{1,2,3},{2,1},{1,2,4,3},{2}}');
