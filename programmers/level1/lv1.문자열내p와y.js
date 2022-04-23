function solution(s) {
  s = s
    .toLowerCase()
    .split("")
    .filter((v) => v === "p" || v === "y");
  let pCount = 0;
  let yCount = 0;

  for (const x of s) {
    x === "p" ? pCount++ : yCount++;
  }

  return pCount === yCount;
}
