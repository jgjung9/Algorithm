const string = prompt()
  .split(" ")
  .map((value) => parseInt(value))
  .sort();

let bool = true;
for (let i = 0; i < string.length - 1; i++) {
  const difference = string[i + 1] - string[i];
  if (difference !== 1) {
    bool = false;
  }
}

if (bool) {
  console.log("YES");
} else {
  console.log("NO");
}
