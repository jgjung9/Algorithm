// 간결하게 정리해서 다시 풀어보자
function solution(N, stages) {
    const clearNum = [];
    const arriveNum = [];

    for (let x of stages) {
        // 클리어한 스테이지 체크
        for (let i = 1; i < x; i++) {
            if (!clearNum[i - 1]) {
                clearNum.push(1);
                continue;
            }

            clearNum[i - 1]++;
        }

        // 도달한 스테이지 체크
        for (let i = 1; i <= x; i++) {
            if (!arriveNum[i - 1]) {
                arriveNum.push(1);
                continue;
            }

            arriveNum[i - 1]++;
        }
    }
    const answer = [];

    for (let i = 0; i < N; i++) {
        if (arriveNum[i] === undefined) {
            answer.push([i + 1, 0]);
            continue;
        }
        if (clearNum[i] === undefined) {
            answer.push([i + 1, 1]);
            continue;
        }
        answer.push([i + 1, (arriveNum[i] - clearNum[i]) / arriveNum[i]]);
    }
    answer.sort((a, b) => b[1] - a[1]).forEach((item) => item.pop());
    return answer.flat();
}

solution(4, [4, 4, 4, 4, 4]);
// 5	[2, 1, 2, 6, 2, 4, 3, 3]	[3,4,2,1,5]
// 4	[4,4,4,4,4]	[4,1,2,3]
