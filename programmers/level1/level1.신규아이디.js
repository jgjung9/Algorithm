// 정규 표현식으로 다시 풀어보자
function solution(new_id) {
    let answer = new_id;
    // 단계 1
    answer = answer.toLowerCase();

    // 단계 2
    answer = answer
        .split("")
        .map((cur) => {
            if (cur === "." || cur === "_" || cur === "-") {
                return cur;
            }
            if (
                cur.charCodeAt(0) >= "a".charCodeAt(0) &&
                cur.charCodeAt(0) <= "z".charCodeAt(0)
            ) {
                return cur;
            }
            if (
                cur.charCodeAt(0) >= "0".charCodeAt(0) &&
                cur.charCodeAt(0) <= "9".charCodeAt(0)
            ) {
                return cur;
            }
            return "";
        })
        .join("");

    // 단계 3
    let pre;
    answer = answer.split("");
    answer.forEach((element, index) => {
        if (index === 0) {
            pre = element;
            return;
        }
        if (pre === "." && pre === element) {
            answer[index] = "";
        } else {
            pre = element;
        }
    });
    answer = answer.join("");

    // 단계 4
    answer = answer.split("");
    if (answer[0] === ".") {
        answer.shift();
    }

    if (answer[answer.length - 1] === ".") {
        answer.pop();
    }
    answer = answer.join("");

    // 단계 5
    if (answer === "") {
        answer = "a";
    }

    // 단계 6
    if (answer.length > 15) {
        answer = answer.substring(0, 15);
        if (answer[14] === ".") {
            answer = answer.substring(0, 14);
        }
    }

    // 단계 7
    const last = answer[answer.length - 1];
    const diff = 3 - answer.length;
    for (let i = 0; i < diff; i++) {
        answer += last;
    }

    console.log(answer);
    return answer;
}

solution("=.=");

// 예1	"...!@BaT#*..y.abcdefghijklm"	"bat.y.abcdefghi"
// 예2	"z-+.^."	"z--"
// 예3	"=.="	"aaa"
// 예4	"123_.def"	"123_.def"
// 예5	"abcdefghijklmn.p"	"abcdefghijklmn"
