/**
 * https://www.acmicpc.net/problem/1011
 *
 * hint: 최단 시간으로 목적지에 도달, 마지막 이동의 거리는 1이어야 한다.
 * 첫 이동은 -1 0 1이 가능하므로 최단으로 가려면 무조건 1이 선택된다.
 * 첫 이동이 1이고 마지막 이동이 1이고, 최단시간내 도달하면
 * 이동은 대칭적으로 발생 할 수 밖에 없다. 즉
 * 최대 이동한 거리가 n라고 가정할 경우 1 2 3 ... n ... 3 2 1 이동이 기본적으로 발생하고
 * 최소 2n - 1이동이 발생한다.
 * 남은 거리 1 ~ n 일 경우 한번의 추가 이동이 발생한다.
 * 남은 거리 n + 1 ~ 2n 일경우 2번의 추가 이동이 발생한다.
 * 남은 거리 2n + 1 일 경우 1 2 3 ... n n+1 n ... 3 2 1 가 된다.
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const T = +input.shift();

const answer = [];
for (let i = 0; i < T; i++) {
    const [x, y] = input[i].split(' ').map(Number);
    const distance = y - x;

    let count = 0;
    for (let max = 1; ; max++) {
        const diff = distance - max * max;
        if (diff > 2 * max) {
            continue;
        }

        if (diff === 0) {
            count = 2 * max - 1;
            break;
        } else if (diff <= max) {
            count = 2 * max;
            break;
        } else if (diff <= 2 * max) {
            count = 2 * max + 1;
            break;
        }
    }
    answer.push(count);
}

console.log(answer.join('\n'));
