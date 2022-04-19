const n = parseInt(prompt());

function decimalToBinary(n) {
  let binary = "";
  let remain;
  while (n > 0) {
    remain = n % 2;
    binary += remain;
    n = Math.floor(n / 2);
  }
  return binary;
}

console.log(decimalToBinary(n));
