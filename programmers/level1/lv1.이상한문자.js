function solution(s) {
  s = s.split(" ").map((str) => {
    str = str.split("").map((char, index) => {
      if (index % 2 === 1) return char.toLowerCase();
      return char.toUpperCase();
    });
    return str.join("");
  });
  return s.join(" ");
}
