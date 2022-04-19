const limitWeight = parseInt(prompt());
const n = parseInt(prompt());
let count = 0;
let sum = 0;
for (let i = 0; i < n; i++) {
  const weight = parseInt(prompt());
  sum += weight;
  if (sum < limitWeight) {
    count++;
  }
}

console.log(count);
