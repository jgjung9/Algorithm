function solution(phone_number) {
  let answer = phone_number
    .split("")
    .map((value, index) => {
      if (index < phone_number.length - 4) {
        value = "*";
      }
      return value;
    })
    .join("");

  return answer;
}

console.log(solution("01033334444"));
