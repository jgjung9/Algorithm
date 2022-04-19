const scores = prompt().split(" ");
let avg = 0;

for (let i = 0; i < scores.length; i++) {
  avg += parseInt(scores[i]);
}

console.log(avg / scores.length);
