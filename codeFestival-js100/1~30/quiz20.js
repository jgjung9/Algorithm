const n = prompt().split(" ");

const quotient = Math.floor(parseInt(n[0]) / parseInt(n[1]));
const remain = parseInt(n[0]) % parseInt(n[1]);

console.log(quotient, remain);
