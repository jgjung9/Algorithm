/**
 * Map을 이용 인덱스 찾기
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  const ans = [];
  const numsMap = new Map();
  nums.forEach((v, idx) => {
    numsMap.has(v)
      ? numsMap.set(v, [...numsMap.get(v), idx])
      : numsMap.set(v, [idx]);
  });

  nums.some((v, idx) => {
    if (numsMap.has(target - v)) {
      const indices = numsMap.get(target - v);
      for (let i = 0; i < indices.length; i++) {
        if (idx !== indices[i]) {
          ans.push(idx, indices[i]);
          return true;
        }
      }
    }
  });

  return ans;
};

console.log(twoSum([3, 3], 6));
