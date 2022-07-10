/**
 * 애너그램
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
  const anagrams = new Map();
  const ans = [];

  strs.forEach((str) => {
    const sorted = str.split('').sort().join('');
    anagrams.has(sorted)
      ? anagrams.set(sorted, [...anagrams.get(sorted), str])
      : anagrams.set(sorted, [str]);
  });
  anagrams.forEach((v) => {
    ans.push(v);
  });

  ans.sort((a, b) => {
    return a.length - b.length;
  });

  return ans;
};

groupAnagrams(['eat', 'tea', 'tan', 'ate', 'nat', 'bat']);
