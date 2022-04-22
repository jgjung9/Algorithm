function solution(absolutes, signs) {
  let answer = 0;

  signs.forEach((bool, index) => {
    bool ? (answer += absolutes[index]) : (answer -= absolutes[index]);
  });

  return answer;
}

console.log(solution([4, 7, 12], [(true, false, true)]));

// [4,7,12]	[true,false,true]	9
// [1,2,3]	[false,false,true]	0
