/**
 * 가장 긴 펠린드롬 찾기 투포인터 알고리즘 사용
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
  const isPalindrome = (lp, rp) => {
    while (lp < rp) {
      if (s[lp++] != s[rp--]) return false;
    }
    return true;
  };

  for (let i = s.length; i > 0; i--) {
    for (let j = 0; j <= s.length - i; j++) {
      if (isPalindrome(j, j + i - 1)) {
        return s.slice(j, j + i);
      }
    }
  }
};

console.log(longestPalindrome('babad'));
