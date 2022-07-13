/**
 * two pointer 를 활용한 풀이
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  const ans = [];
  nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length - 2; i++) {
    if (i && nums[i - 1] === nums[i]) continue;
    let j = i + 1;
    let k = nums.length - 1;
    while (j < k) {
      if (j > i + 1 && nums[j] === nums[j - 1]) {
        j++;
        continue;
      }
      if (k < nums.length - 1 && nums[k] === nums[k + 1]) {
        k--;
        continue;
      }

      const sum = nums[i] + nums[j] + nums[k];
      if (sum < 0) {
        j++;
        continue;
      } else if (sum > 0) {
        k--;
        continue;
      } else {
        ans.push([nums[i], nums[j], nums[k]]);
        j++, k--;
      }
    }
  }
  return ans;
};

console.log(threeSum([0, 0, 0]));
