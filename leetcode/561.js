/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function (nums) {
  let ans = 0;
  nums.sort((a, b) => b - a);
  while (nums.length > 0) {
    ans += nums.pop();
    nums.pop();
  }
  return ans;
};
