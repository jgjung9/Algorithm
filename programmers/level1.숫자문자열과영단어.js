// 정규 표현식 공부해서 다시 풀어보기 or replace로도 단순하게 구현 가능
function solution(s) {
  let answer = "";

  const number = {
    zero: 0,
    one: 1,
    two: 2,
    three: 3,
    four: 4,
    five: 5,
    six: 6,
    seven: 7,
    eight: 8,
    nine: 9,
  };

  let str = "";
  for (let x of s) {
    if (
      x.charCodeAt(0) < "0".charCodeAt(0) ||
      x.charCodeAt(0) > "9".charCodeAt(0)
    ) {
      str += x;
      if (number[str] !== undefined) {
        answer += String(number[str]);
        str = "";
      }
    } else {
      answer += x;
    }
  }

  return +answer;
}

console.log(solution("123"));

// "one4seveneight"	1478
// "23four5six7"	234567
// "2three45sixseven"	234567
// "123"	123
