/**
 * https://www.acmicpc.net/problem/2579
 *
 * hint: 도착지를 기준으로 생각해보면,
 * 1칸 올라오는 경우와 2칸 올라와 도달하는 경우 2가지로 나눌수 있다.
 * 1칸의 경우 도착지 + 도착지전 계단 + 도착지 3전계단을 무조건 밟게 된다.
 * 따라서 dp[n] = values[n] + values[n-1] + dp[n-3] 이고
 * 2칸 올라오는 경우는 도착지 도착지 2전계단을 무조건 밟게 된다.
 * 따라서 dp[n] = values[n] + dp[n-2]
 * 따라서 2 경우의 최대가 dp[n]에 들어가게 된다. *
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const N = +input[0];
const values = Array.from(input).map(Number);
values[0] = 0;

const dp = [values[0], values[1], values[1] + values[2]];

for (let i = 3; i <= N; i++) {
    dp[i] = Math.max(
        dp[i - 3] + values[i] + values[i - 1],
        dp[i - 2] + values[i]
    );
}

console.log(dp[N]);
