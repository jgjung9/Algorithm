function solution(participant, completion) {
  let answer = "";
  const candidate = new Map();

  participant.forEach((val) => {
    candidate.has(val)
      ? candidate.set(val, candidate.get(val) + 1)
      : candidate.set(val, 1);
  });

  completion.forEach((winner) => {
    candidate.set(winner, candidate.get(winner) - 1);
  });

  candidate.forEach((value, key) => {
    if (value !== 0) {
      answer = key;
    }
  });

  return answer;
}

console.log(solution(["leo", "kiki", "eden"], ["eden", "kiki"]));
// ["leo", "kiki", "eden"]	["eden", "kiki"]	"leo"
// ["marina", "josipa", "nikola", "vinko", "filipa"]	["josipa", "filipa", "marina", "nikola"]	"vinko"
// ["mislav", "stanko", "mislav", "ana"]	["stanko", "ana", "mislav"]	"mislav"
