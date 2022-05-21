/**
 * https://www.acmicpc.net/problem/1931
 *
 * hint: 끝나는 시간을 기준으로 내림차순으로 정렬한다.
 * 맨뒤에 있는 회의를 시작한다. 회의의 끝나는 시각을 시작시간으로 변경하고
 * 변경된 시작시간보다 일찍시작하는 것을 제거한다.
 * 반복한다.
 *
 * +a 시작과 끝나는 시간이 동일할 경우 단순히 종료시간만을 기준으로 할 경우
 * 더 늦게 시작하는것이 입력에 따라 먼저 뽑아져 나와 문제가 발생할 수 있다.
 * 따라서 먼저 시작시간을 내림차순으로 정렬한 후 종료시간을 내림차순으로 정렬해야 한다.
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const N = input[0];
const meetings = [];

input.slice(1).forEach((meeting) => {
    const time = meeting.split(' ').map(Number);
    meetings.push(time);
});

meetings.sort((a, b) => b[0] - a[0]).sort((a, b) => b[1] - a[1]);

let count = 0;
let start = 0;
while (meetings.length > 0) {
    const meeting = meetings.pop();
    if (start <= meeting[0]) {
        start = meeting[1];
        count++;
    }
}

console.log(count);
