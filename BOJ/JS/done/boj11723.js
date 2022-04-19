const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().trim().split("\r\n");
const [N, M] = input.shift().split(" ").map(Number);
const siteMap = new Map();
const searchSite = input.slice(input.length - M);

input.slice(0, input.length - M).forEach((item) => {
  const [site, password] = item.split(" ");
  if (!siteMap.has(site)) {
    siteMap.set(site, password);
  }
});

searchSite.forEach((item) => {
  console.log(siteMap.get(item));
});
