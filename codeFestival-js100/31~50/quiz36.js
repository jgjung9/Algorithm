const n = 2; //parseInt(promt());
let result = "";

for (let i = 1; i <= 9; i++) {
  const value = n * i;
  result += `${value} `;
}

console.log(result);
