function solution(numbers, hand) {
    let answer = "";

    const board = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
        ["*", 0, "#"],
    ];

    let leftHand = [3, 0];
    let rightHand = [3, 2];

    for (let n of numbers) {
        let xPos = Math.ceil(n / 3) - 1;
        let yPos = n % 3 === 0 ? 2 : (n % 3) - 1;
        if (n === 0) {
            xPos = 3;
            yPos = 1;
        }
        if (yPos === 0) {
            leftHand = [xPos, yPos];
            answer += "L";
            continue;
        } else if (yPos === 2) {
            rightHand = [xPos, yPos];
            answer += "R";
            continue;
        }

        let leftDis =
            Math.abs(leftHand[0] - xPos) + Math.abs(leftHand[1] - yPos);
        let rightDis =
            Math.abs(rightHand[0] - xPos) + Math.abs(rightHand[1] - yPos);

        if (leftDis === rightDis) {
            if (hand === "right") {
                rightHand = [xPos, yPos];
                answer += "R";
            } else {
                leftHand = [xPos, yPos];
                answer += "L";
            }
        } else if (leftDis < rightDis) {
            leftHand = [xPos, yPos];
            answer += "L";
        } else {
            rightHand = [xPos, yPos];
            answer += "R";
        }
    }

    return answer;
}

console.log(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"));
