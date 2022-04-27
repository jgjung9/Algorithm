function solution(nums) {
    const phoneketmon = new Set(nums);
    return phoneketmon.size > nums.length / 2
        ? nums.length / 2
        : phoneketmon.size;
}

console.log(solution([3, 3, 3, 2, 2, 2]));

// [3,1,2,3]	2
// [3,3,3,2,2,4]	3
// [3,3,3,2,2,2]	2
