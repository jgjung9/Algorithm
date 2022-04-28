// 모든 경우 나눠서 푼 풀이
// 너무 복잡하고 어려움 BFS로 간단하게 다시 풀어보자
function check(place) {
    for (let i = 0; i < place.length; i++) {
        for (let j = 0; j < place[0].length; j++) {
            if (place[i][j] === "P") {
                // 위 확인
                if (i - 1 >= 0 && place[i - 1][j] === "P") return 0;
                // 아래 확인
                if (i + 1 < place.length && place[i + 1][j] === "P") return 0;
                // 왼쪽 확인
                if (j - 1 >= 0 && place[i][j - 1] === "P") return 0;
                // 오른쪽 확인
                if (j + 1 < place[0].length && place[i][j + 1] === "P")
                    return 0;

                // 좌상단 확인
                if (i - 1 >= 0 && j - 1 >= 0 && place[i - 1][j - 1] === "P") {
                    if (place[i - 1][j] === "O" || place[i][j - 1] === "O")
                        return 0;
                }

                // 우상단 확인
                if (
                    i - 1 >= 0 &&
                    j + 1 < place[0].length &&
                    place[i - 1][j + 1] === "P"
                ) {
                    if (place[i - 1][j] === "O" || place[i][j + 1] === "O")
                        return 0;
                }

                // 좌하단 확인
                if (
                    i + 1 < place.length &&
                    j - 1 >= 0 &&
                    place[i + 1][j - 1] === "P"
                ) {
                    if (place[i + 1][j] === "O" || place[i][j - 1] === "O")
                        return 0;
                }

                // 우하단 확인
                if (
                    i + 1 < place.length &&
                    j + 1 < place[0].length &&
                    place[i + 1][j + 1] === "P"
                ) {
                    if (place[i + 1][j] === "O" || place[i][j + 1] === "O")
                        return 0;
                }

                // 일직성 상 거리가 2인 경우 확인
                // 상
                if (
                    i - 2 >= 0 &&
                    place[i - 1][j] === "O" &&
                    place[i - 2][j] === "P"
                )
                    return 0;
                // 하
                if (
                    i + 2 < place.length &&
                    place[i + 1][j] === "O" &&
                    place[i + 2][j] === "P"
                )
                    return 0;
                // 좌
                if (
                    j - 2 >= 0 &&
                    place[i][j - 1] === "O" &&
                    place[i][j - 2] === "P"
                )
                    return 0;
                // 우
                if (
                    j + 2 < place[0].length &&
                    place[i][j + 1] === "O" &&
                    place[i][j + 2] === "P"
                )
                    return 0;
            }
        }
    }
    return 1;
}

function solution(places) {
    const answer = [];

    places.forEach((place) => {
        answer.push(check(place));
    });
    return answer;
}

console.log(
    solution([
        ["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"],
        ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"],
        ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"],
        ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"],
        ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"],
    ])
);
