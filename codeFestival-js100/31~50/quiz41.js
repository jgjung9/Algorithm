const n = parseInt(prompt());
let result = true;

for (let i = 2; i * i <= n; i++) {
  if (n % i === 0) {
    result = false;
  }
}

if (result) {
  console.log("YES");
} else {
  console.log("NO");
}
