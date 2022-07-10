/**
 * 문자열 처리와 해쉬맵을 이용한 빈도 체크
 * @param {string} paragraph
 * @param {string[]} banned
 * @return {string}
 */
var mostCommonWord = function (paragraph, banned) {
  const wordMap = new Map();
  paragraph
    .toLowerCase()
    .replace(/[^a-z ]/g, ' ')
    .split(' ')
    .filter((s) => s !== '' && !banned.includes(s))
    .forEach((word) => {
      wordMap.has(word)
        ? wordMap.set(word, wordMap.get(word) + 1)
        : wordMap.set(word, 1);
    });
  let ans;
  let max = 0;
  wordMap.forEach((v, k) => {
    if (v > max) {
      max = v;
      ans = k;
    }
  });
  console.log(ans);
  return ans;
};

mostCommonWord('a, a, a, a, b,b,b,c, c', ['a']);
