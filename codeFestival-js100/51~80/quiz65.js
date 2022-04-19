const a = [1, 2, 3, 4];
const b = ["a", "b", "c", "d"];

let list = a.map((item, index) => [item, b[index]]);
let list2 = [];
a.forEach((item, index) => list2.push([item, b[index]]));
console.log(list);
console.log(list2);
