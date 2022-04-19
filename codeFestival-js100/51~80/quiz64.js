const n = parseInt(prompt());
let bool = false;
let count;

for (let i = 0; 3 * i < n; i++) {
  console.log(count);
  for (let j = 0; 7 * j < n; j++) {
    count = i + j;
    if (j * 7 + i * 3 === n) {
      bool = true;
      break;
    }
  }
  if (bool) {
    break;
  }
}

if (!bool) {
  console.log(-1);
} else {
  console.log(count);
}
