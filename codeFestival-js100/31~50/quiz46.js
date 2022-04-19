let str = "";
for (let i = 1; i <= 20; i++) {
  str += i;
}

const array = str.split("").map((value) => parseInt(value));
let sum = 0;
for (let i = 0; i < array.length; i++) {
  sum += array[i];
}

console.log(sum);
