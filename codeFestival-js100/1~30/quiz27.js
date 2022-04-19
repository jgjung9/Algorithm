const keys = prompt().split(" ");
const values = prompt().split(" ");
const obj = {};

for (let i = 0; i < keys.length; i++) {
  obj[keys[i]] = parseInt(values[i], 10);
}

console.log(obj);
