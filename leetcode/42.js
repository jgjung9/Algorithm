/**
 * 투포인터를 이용한 풀이
 * @param {number[]} height
 * @return {number}
 */
var trap = function (height) {
  let ans = 0;
  let l = 0;
  let r = height.length - 1;
  let lMax = height[l];
  let rMax = height[r];

  while (l < r) {
    lMax = Math.max(lMax, height[l]);
    rMax = Math.max(rMax, height[r]);

    if (lMax > rMax) {
      ans += rMax - height[r];
      r--;
    } else {
      ans += lMax - height[l];
      l++;
    }
  }
  return ans;
};

console.log(trap([5, 5, 1, 7, 1, 1, 5, 2, 7, 6]));
