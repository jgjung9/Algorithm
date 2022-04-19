// const scores = ["97", "86", "75", "66", "55", "97", "85", "97", "97", "95"]; //prompt().split(" ");
// const result = {};

// for (const key of scores) {
//   result[key] === undefined ? (result[key] = 1) : (result[key] += 1);
// }
// console.log(result);

// let output = Object.keys(result).sort((a, b) => b - a);
// output =
//   parseInt(result[output[0]]) +
//   parseInt(result[output[1]]) +
//   parseInt(result[output[2]]);

// console.log(output);

const scores = [97, 86, 75, 66, 55, 97, 85, 97, 97, 95].sort((a, b) => a - b); //prompt().split(" ");
console.log(scores);

let result = [];
let count = 0;

while (result.length < 4) {
  const value = scores.pop();
  if (!result.includes(value)) {
    result.push(value);
  }
  count++;
}
count--;

console.log(count);
