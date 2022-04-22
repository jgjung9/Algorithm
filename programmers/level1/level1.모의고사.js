function correctCount(answers, student) {
  let count = 0;

  answers.forEach((value, index) => {
    if (student[index % student.length] === value) {
      count++;
    }
  });

  return count;
}

function solution(answers) {
  let answer = [];
  const count = [];
  const students = [
    [1, 2, 3, 4, 5],
    [2, 1, 2, 3, 2, 4, 2, 5],
    [3, 3, 1, 1, 2, 2, 4, 4, 5, 5],
  ];

  for (const student of students) {
    count.push(correctCount(answers, student));
  }

  const maxCount = Math.max(...count);
  count.forEach((value, index) => {
    if (value === maxCount) {
      answer.push(index + 1);
    }
  });

  return answer;
}

console.log(solution([1, 3, 2, 4, 2], [1]));

// [1,2,3,4,5],	[1]
// [1,3,2,4,2],	[1,2,3]
