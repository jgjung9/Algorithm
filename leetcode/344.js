/**
 * two pointer 알고리즘 연습 문자열 스왑
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function (s) {
  let lp = 0;
  let rp = s.length - 1;
  while (lp < rp) {
    [s[lp], s[rp]] = [s[rp], s[lp]];
    lp++, rp--;
  }
  return s;
};
