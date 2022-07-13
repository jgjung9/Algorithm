/**
 * 나눗셈을 사용하지 말라는 제약조건을 잘 지키면서 O(n)으로 해결하는 것이 핵심
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
  let zeroCnt = 0;
  nums.forEach((v, idx) => {
    if (v === 0) zeroCnt++;
  });

  if (zeroCnt > 1) return Array(nums.length).fill(0);
  else if (zeroCnt === 1) {
    let product = 1;
    nums.forEach((v) => {
      if (v === 0) return;
      product *= v;
    });
    return nums.map((v) => {
      return v === 0 ? product : 0;
    });
  } else {
    const leftProduct = [];
    let rightProduct = [];

    let l = 0;
    let r = nums.length - 1;
    let left = 1;
    let right = 1;
    while (l < nums.length && r >= 0) {
      left *= nums[l++];
      right *= nums[r--];
      leftProduct.push(left);
      rightProduct.push(right);
    }
    rightProduct = rightProduct.reverse();
    const ans = [];
    for (let i = 0; i < nums.length; i++) {
      if (i == 0) ans.push(rightProduct[i + 1]);
      else if (i === nums.length - 1) ans.push(leftProduct[i - 1]);
      else ans.push(leftProduct[i - 1] * rightProduct[i + 1]);
    }
    return ans;
  }
};

console.log(productExceptSelf([1, 2, 3, 4]));
