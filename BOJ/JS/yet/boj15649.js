const fs = require("fs");
const [N, M] = fs.readFileSync("./input.txt").toString().split(" ").map(Number);

console.log(N, M);
