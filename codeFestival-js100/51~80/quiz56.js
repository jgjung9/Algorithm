const nationWidth = {
  korea: 220877,
  Rusia: 17098242,
  China: 9596961,
  France: 543965,
  Japan: 377915,
  England: 242900,
};

const koreaWidth = nationWidth.korea;
delete nationWidth.korea;
let min = 1111111110;
let country = "";
for (let obj in nationWidth) {
  //   console.log(obj);
  if (min > Math.abs(nationWidth[obj] - koreaWidth)) {
    min = nationWidth[obj] - koreaWidth;
    country = obj;
  }
}

console.log(`${country} ${min}`);
