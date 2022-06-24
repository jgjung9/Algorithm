function solution(record) {
  var answer = [];
  const ids = new Map();
  record.forEach((r) => {
    const [command, id, name] = r.split(' ');
    if (command === 'Enter' || command === 'Change') ids.set(id, name);
  });

  record.forEach((r) => {
    const [command, id, _] = r.split(' ');
    if (command === 'Enter') answer.push(`${ids.get(id)}님이 들어왔습니다.`);
    else if (command === 'Leave') answer.push(`${ids.get(id)}님이 나갔습니다.`);
  });

  return answer;
}

solution([
  'Enter uid1234 Muzi',
  'Enter uid4567 Prodo',
  'Leave uid1234',
  'Enter uid1234 Prodo',
  'Change uid4567 Ryan',
]);
