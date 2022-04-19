const election = [
  "원범",
  "원범",
  "혜원",
  "혜원",
  "혜원",
  "혜원",
  "유진",
  "유진",
];
const obj = {};

for (const name of election) {
  obj[name] === undefined ? (obj[name] = 1) : (obj[name] += 1);
}
const winner = Object.keys(obj).reduce((a, b) => (obj[a] > obj[b] ? a : b));
console.log(`${winner}(이)가 총 ${obj[winner]}표로 반장이 되었습니다.`);
