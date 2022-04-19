function countOne(n) {
  let count = 0;
  for (let i = 0; i <= n; i++) {
    const one = i
      .toString()
      .split("")
      .filter((item) => item === "1");
    count += one.length;
  }
  return count;
}

console.log(countOne(20));
