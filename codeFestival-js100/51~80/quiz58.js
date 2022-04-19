let money = prompt().split("");

let len = money.length;
while (true) {
  len -= 3;
  if (len > 0) {
    money.splice(len, 0, ",");
  } else {
    break;
  }
}
console.log(money.join(""));
