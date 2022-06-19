const fs = require('fs');
let input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const [a, b, c] = input[0].split(' ').map(Number);
const regularMenu = new Map();
const specialMenu = new Map();
const serviceMenu = new Set();
let regularPrice = 0;
let specialPrice = 0;
let serviceCnt = 0;

input.slice(1, a + 1).forEach((item) => {
  const [name, price] = item.split(' ');
  regularMenu.set(name, +price);
});
input = input.slice(a + 1);

input.slice(0, b).forEach((item) => {
  const [name, price] = item.split(' ');
  specialMenu.set(name, +price);
});
input = input.slice(b);

input.slice(0, c).forEach((item) => {
  serviceMenu.add(item);
});
input = input.slice(c + 1);

input.forEach((item) => {
  if (regularMenu.has(item)) regularPrice += regularMenu.get(item);
  else if (specialMenu.has(item)) specialPrice += specialMenu.get(item);
  else if (serviceMenu.has(item)) serviceCnt++;
});

if (serviceCnt) {
  if (serviceCnt > 1) console.log('No');
  else if (regularPrice >= 20000 && regularPrice + specialPrice >= 50000)
    console.log('Okay');
  else console.log('No');
} else if (specialPrice) {
  regularPrice >= 20000 ? console.log('Okay') : console.log('No');
} else console.log('Okay');
