function solution(dartResult) {
    const answer = [];
    const regex = /[0-9][0]?[SDT][*#]?/g;
    dartResult = dartResult.match(regex);

    dartResult.forEach((item, index) => {
        let value = (bonus = option = "");
        for (let x of item) {
            if (isNaN(x)) {
                if (x === "S" || x === "D" || x === "T") {
                    bonus += x;
                }
                if (x === "*" || x === "#") {
                    option += x;
                }
            } else {
                value += x;
            }
        }

        value = Number(value);

        switch (bonus) {
            case "D":
                value = Math.pow(value, 2);
                break;
            case "T":
                value = Math.pow(value, 3);
                break;
        }
        switch (option) {
            case "*":
                value *= 2;
                if (index !== 0) {
                    answer[index - 1] *= 2;
                }
                break;
            case "#":
                value *= -1;
                break;
        }
        answer.push(value);
    });
    return answer.reduce((sum, value) => (sum += value), 0);
}

console.log(solution("1D2S#10S"));

// 예제	dartResult	answer	    설명
// 1	1S2D*3T	    37	    11 * 2 + 22 * 2 + 33s
// 2	1D2S#10S	 9	    12 + 21 * (-1) + 101
// 3	1D2S0T	     3	    12 + 21 + 03
// 4	1S*2T*3S	23	    11 * 2 * 2 + 23 * 2 + 31
// 5	1D#2S*3S	 5	    12 * (-1) * 2 + 21 * 2 + 31
// 6	1T2D3D#	    -4	    13 + 22 + 32 * (-1)
// 7	1D2S3T*	    59	    12 + 21 * 2 + 33 * 2
