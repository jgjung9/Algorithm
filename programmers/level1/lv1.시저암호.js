function solution(s, n) {
  const lowerCase = "abcdefghijklmnopqrstuvwxyz";
  const upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  s = s.split("").map((char) => {
    if (char === " ") return char;
    if (lowerCase.includes(char)) {
      return lowerCase[(lowerCase.indexOf(char) + n) % 26];
    } else return upperCase[(upperCase.indexOf(char) + n) % 26];
  });
  return s.join("");
}
