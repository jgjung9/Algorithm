/**
 * two pointer를 이용한 펠린드롬 판별
 * O(n)의 시간 복잡도를 가진다.
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
  s = s.toLowerCase();
  s = s.replace(/[^a-z0-9]/g, '');
  let lp = 0;
  let rp = s.length - 1;
  while (lp < rp) {
    if (s[lp++] != s[rp--]) return false;
  }
  return true;
};

console.log(isPalindrome('A man, a plan, a canal: Panama'));
