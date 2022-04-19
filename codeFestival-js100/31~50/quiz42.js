const month = parseInt(prompt());
const day = parseInt(prompt());
const dayList = ["SUN", "MON", "TUE", "WED", "TUR", "FRI", "SAT"];

let date = new Date();
date.setFullYear(2020);
date.setMonth(month, day);

console.log(dayList[date.getDay()]);
