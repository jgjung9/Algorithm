const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split(' ');
const [min, max] = input.map(Number);
const visited = Array(max - min + 1).fill(false);

for (let i = 2; i * i <= max; i++) {
  const squre = i * i;
  let start = Math.ceil(min / squre) * squre;
  for (let j = start; j <= max; j += squre) {
    visited[j - min] = true;
  }
}

let ans = 0;
visited.forEach((v) => {
  if (!v) ans++;
});

console.log(ans);
