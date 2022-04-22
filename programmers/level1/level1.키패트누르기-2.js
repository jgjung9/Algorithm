function solution(numbers, hand) {
  let answer = "";
  // x 세로 y 가로 축
  const keypad = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
    ["*", 0, "#"],
  ];

  let leftPos = [3, 0];
  let rightPos = [3, 2];

  for (let num of numbers) {
    let xPos;
    let yPos;

    if (num === 1 || num === 4 || num === 7) {
      xPos = Math.floor(num / 3);
      yPos = 0;
      answer += "L";
      leftPos = [xPos, yPos];
      continue;
    }

    if (num === 3 || num === 6 || num === 9) {
      xPos = num / 3 - 1;
      yPos = 2;
      answer += "R";
      rightPos = [xPos, yPos];
      continue;
    }

    if (num === 0) {
      xPos = 3;
      yPos = 1;
    } else {
      xPos = Math.floor(num / 3);
      yPos = 1;
    }

    const distanceLeft =
      Math.abs(leftPos[0] - xPos) + Math.abs(leftPos[1] - yPos);
    const distanceRight =
      Math.abs(rightPos[0] - xPos) + Math.abs(rightPos[1] - yPos);

    if (distanceLeft === distanceRight) {
      if (hand === "right") {
        answer += "R";
        rightPos = [xPos, yPos];
      } else {
        answer += "L";
        leftPos = [xPos, yPos];
      }
    } else if (distanceLeft < distanceRight) {
      answer += "L";
      leftPos = [xPos, yPos];
    } else {
      answer += "R";
      rightPos = [xPos, yPos];
    }
  }

  return answer;
}

console.log(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"));
