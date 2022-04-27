function solution(progresses, speeds) {
    let answer = [];

    // progresses의 첫번째 값이 100이 되도록 하고 연속적으로 100이 넣는 progresses를 모두 빼고
    // 그 개수를 answer에 넣어 반환한다.
    while (progresses.length > 0) {
        let time = Math.ceil(100 - progresses[0] / speeds[0]);
        let count = 0;
        for (let i = 0; i < progresses.length; i++) {
            progresses[i] += speeds[i] * time;
        }

        for (let i = 0; i < progresses.length; i++) {
            if (progresses[i] >= 100) {
                progresses.shift();
                speeds.shift();
                count++;
                i--;
            } else {
                break;
            }
        }

        answer.push(count);
    }
    return answer;
}

solution([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1]);

// [93, 30, 55]	[1, 30, 5]	[2, 1]
// [95, 90, 99, 99, 80, 99]	[1, 1, 1, 1, 1, 1]	[1, 3, 2
