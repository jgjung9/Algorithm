function solution(s) {
    let answer = [];
    for (let i = 1; i <= s.length; i++) {
        // 문자를 i개씩 잘라 result에 넣는다.
        let result = [];
        for (let j = 0; j < s.length; j += i) {
            if (j + i > s.length) {
                result.push(s.slice(j));
            } else {
                result.push(s.slice(j, j + i));
            }
        }

        // result를 순회하며 반복횟수+문자열 형식으로 str을 만든다.
        let str = "";
        let count = 1;
        let pre = result[0];
        for (let i = 1; i < result.length; i++) {
            if (pre === result[i]) {
                count++;
            } else {
                if (count === 1) {
                    str += pre;
                } else {
                    str += count + pre;
                }
                pre = result[i];
                count = 1;
            }
        }
        if (count === 1) {
            str += pre;
        } else {
            str += count + pre;
        }
        answer.push(str.length);
    }

    // answer에 들어간 str의 길이의 최소가 압축된 문자열의 최소 길이
    return Math.min(...answer);
}
console.log(solution("abcabcabcabcdededededede"));

// "aabbaccc"	7
// "ababcdcdababcdcd"	9
// "abcabcdede"	8
// "abcabcabcabcdededededede"	14
// "xababcdcdababcdcd"	17
