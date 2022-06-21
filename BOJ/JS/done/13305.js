const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const n = +input[0];
const distance = input[1].split(' ').map(Number);
const gasStation = input[2].split(' ').map(Number);
let selectedPrice = BigInt(Number.MAX_SAFE_INTEGER);
let ans = BigInt(0);
for (let i = 0; i < n - 1; i++) {
  selectedPrice =
    selectedPrice > BigInt(gasStation[i])
      ? BigInt(gasStation[i])
      : selectedPrice;
  ans += selectedPrice * BigInt(distance[i]);
}
console.log(ans.toString());
