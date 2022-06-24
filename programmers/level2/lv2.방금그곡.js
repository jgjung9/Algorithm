function solution(m, musicinfos) {
  let answer = '';

  m = m.match(/[A-Z]#?/g);
  musicinfos = musicinfos.map((info) => {
    let [start, end, name, code] = info.split(',');
    start = start.split(':').map(Number);
    end = end.split(':').map(Number);
    const time = 60 * (end[0] - start[0]) + (end[1] - start[1]);
    code = code.match(/[A-Z]#?/g);
    const newCode = [];
    for (let i = 0; i < time; i++) {
      newCode.push(code[i % code.length]);
    }
    return [time, name, newCode];
  });

  musicinfos = musicinfos.filter((info) => {
    const len = m.length;
    for (let i = 0; i <= info[2].length - len; i++) {
      if (info[2].slice(i, i + len).join('') === m.join('')) {
        return true;
      }
    }
    return false;
  });

  musicinfos.sort((a, b) => {
    if (a[0] > b[0]) return -1;
    if (a[0] === b[0]) return 0;
    if (a[0] < b[0]) return 1;
  });

  if (musicinfos.length === 0) answer = '(None)';
  else answer = musicinfos[0][1];
  return answer;
}

console.log(
  solution('ABC', ['12:00,12:14,HELLO,C#DEFGAB', '13:00,13:05,WORLD,ABCDEF'])
);
