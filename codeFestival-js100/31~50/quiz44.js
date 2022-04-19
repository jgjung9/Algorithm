const num = prompt()
  .split("")
  .map((value) => parseInt(value));
let sum = 0;
for (let i = 0; i < num.length; i++) {
  sum += num[i];
}
console.log(sum);
