const count = 59; //parseInt(prompt());
let n = 0;
for (n = 1; (n * (n + 1)) / 2 < count; n++);
let answer = [count - ((n - 1) * n) / 2, n + 1];

console.log(answer);
