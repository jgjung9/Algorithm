function solution(n, lost, reserve) {
  let answer;

  // 체육복 도둑질 당한 사람이 여벌의 옷을 가지고 있는 경우를 제거한다.
  const temp = Array.from(lost);
  lost = lost.filter((v) => !reserve.includes(v));
  reserve = reserve.filter((v) => !temp.includes(v));

  while (true) {
    const temp = Array.from(reserve);

    // 여벌이 있고, 줄 수 있는 사람이 한명이 경우 그 사람에게 준다.
    for (let i = 0; i < reserve.length; i++) {
      const number = reserve.shift();

      if (lost.includes(number - 1) && !lost.includes(number + 1)) {
        lost.splice(lost.indexOf(number - 1), 1);
        continue;
      }

      if (lost.includes(number + 1) && !lost.includes(number - 1)) {
        lost.splice(lost.indexOf(number + 1), 1);
        continue;
      }

      reserve.push(number);
    }

    if (JSON.stringify(temp) === JSON.stringify(reserve)) {
      break;
    }
  }

  // 여벌을 가지고 있는 사람 중 남은 인원은 모두 앞 뒤 사람이 도둑을 당한상태 또는 빌려 줄 사람이 없는 경우
  // 앞 사람에게 빌려주는 것으로 통일
  for (let i = 0; i < reserve.length; i++) {
    const number = reserve.shift();

    if (lost.includes(number - 1)) {
      lost.splice(lost.indexOf(number - 1), 1);
      continue;
    }

    reserve.push(number);
  }

  answer = n - lost.length;
  return answer;
}

console.log(solution(3, [1, 2, 3], [1, 2, 3]));

// 5	[2, 4]	[1, 3, 5]	5
// 5	[2, 4]	[3]	4
// 3	[3]	[1]	2
