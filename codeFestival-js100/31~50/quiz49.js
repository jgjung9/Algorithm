const nums = prompt()
  .split(" ")
  .map((value) => parseInt(value))
  .sort((a, b) => b - a);

console.log(nums[0]);
