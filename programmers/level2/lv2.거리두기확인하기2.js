// BFS와 같은 그래프 서치를 하는 방식을 활용해 체크 함수를 구현한 풀이
const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];
function check(y, x, place) {
    const now = place[y][x];
    let count = 0;
    for (let dir = 0; dir < 4; dir++) {
        const nextY = y + dy[dir];
        const nextX = x + dx[dir];
        if (nextY < 0 || nextY >= place.length) continue;
        if (nextX < 0 || nextX >= place[0].length) continue;
        if (now === 'P' && place[nextY][nextX] === 'P') return false;
        else if (now === 'O' && place[nextY][nextX] === 'P') {
            count++;
            if (count >= 2) return false;
        }
    }
    return true;
}

function solution(places) {
    const answer = [];
    places.forEach((place) => {
        let isPossible = true;
        for (let y = 0; y < place.length; y++) {
            for (let x = 0; x < place[0].length; x++) {
                if (place[y][x] !== 'X' && !check(y, x, place))
                    isPossible = false;
            }
        }
        isPossible ? answer.push(1) : answer.push(0);
    });

    return answer;
}

console.log(
    solution([
        ['POOOP', 'OXXOX', 'OPXPX', 'OOXOX', 'POXXP'],
        ['POOPX', 'OXPXP', 'PXXXO', 'OXXXO', 'OOOPP'],
        ['PXOPX', 'OXOXP', 'OXPOX', 'OXXOP', 'PXPOX'],
        ['OOOXX', 'XOOOX', 'OOOXX', 'OXOOX', 'OOOOO'],
        ['PXPXP', 'XPXPX', 'PXPXP', 'XPXPX', 'PXPXP'],
    ])
);
