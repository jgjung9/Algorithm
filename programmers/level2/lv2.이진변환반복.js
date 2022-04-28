function decimalToBinary(n) {
    let answer = "";
    while (n > 0) {
        answer += n % 2;
        n = Math.floor(n / 2);
    }
    return answer.split("").reverse().join("");
}

function solution(s) {
    let removeZeroCnt = 0;
    let transferBinayCnt = 0;

    while (s.length > 1) {
        if (s === "1") {
            break;
        }
        removeZeroCnt += s.split("").filter((v) => v === "0").length;
        s = s
            .split("")
            .filter((v) => v === "1")
            .join("");

        s = decimalToBinary(s.length);
        transferBinayCnt++;
    }

    return [transferBinayCnt, removeZeroCnt];
}

console.log(solution("1111111"));
