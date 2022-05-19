/**
 * https://www.acmicpc.net/problem/11659
 * 
 * hint: 1 ≤ N ≤ 100,000 1 ≤ M ≤ 100,000 이므로 단순 이중 루프를 진행하게 될 경우 n^2 시간 복잡도를 가지게 된다.
 * 따라서 루프를 M번만 돌아 해결할 수 있는 방식으로 문제으로 해결해야 한다.
 * DP 방식으로 구간합의 배열을 사전에 구하는 방식을 사용
 *
 * +a 처음 시도했을 시 M번 도는 루프속에서 console.log()를 진행하여 시간초과가 발생
 * console.log()를 M번 반복하는 것을 많은 시간을 소요하므로 answer 배열에 값을 넣어
 * 루프를 빠져나온 후 answer를 출력하는 방식으로 진행
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const [N, M] = input[0].split(' ').map(Number);
const numList = input[1].split(' ').map(Number);
const ranges = input.slice(2);

const sumList = [0, numList[0]];
const answer = [];

for (let i = 1; i < N; i++) {
    sumList.push(numList[i] + sumList[i]);
}

for (let i = 0; i < M; i++) {
    const range = ranges[i].split(' ').map(Number);
    answer.push(sumList[range[1]] - sumList[range[0] - 1]);
}

console.log(answer.join('\n'));