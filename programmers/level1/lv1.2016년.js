function solution(a, b) {
  const day = ["THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"];
  const month = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

  let sum = b;
  for (let i = 0; i < a - 1; i++) {
    sum += month[i];
  }

  return day[sum % 7];
}
