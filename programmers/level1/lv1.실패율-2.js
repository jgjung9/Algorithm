function solution(N, stages) {
    const answer = [];
    const result = [];
    for (let i = 0; i <= N; i++) {
        const obj = {
            stage: i + 1,
            clear: 0,
            arrive: 0,
            failRate: 0,
        };
        result.push(obj);
    }
    for (let stage of stages) {
        for (let i = 1; i < stage; i++) {
            result[i - 1].clear++;
            result[i - 1].arrive++;
        }
        result[stage - 1].arrive++;
    }
    result.pop();

    for (let x of result) {
        x.failRate = (x.arrive - x.clear) / x.arrive;
    }
    result.sort((a, b) => b.failRate - a.failRate);
    for (let x of result) {
        answer.push(x.stage);
    }

    return answer;
}

console.log(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]));
// 5	[2, 1, 2, 6, 2, 4, 3, 3]	[3,4,2,1,5]
// 4	[4,4,4,4,4]	                [4,1,2,3]
