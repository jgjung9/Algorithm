/**
 * https://www.acmicpc.net/problem/11047
 * 
 * hint: (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)
 * 위 조건으로 인해 모든 코인은 하위 코인의 배수로 만들수 있게 된다.
 * 즉 Ai 코인은 Aj (1 ≤ j ≤ i-1) 코인의 곱으로 나타 낼수 있다.
 * 코인으로 만들고자 하는 값이 애초에 불가한 값이 아닌경우
 * 상위코인부터 차례대로 채워 나가면 코인의 개수가 가장 작아지게 된다.
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const [N, K] = input.shift().split(' ').map(Number);
const coins = input.map(Number).filter(value => value <= K).reverse();

let count = 0;
let remain = K;

for (let coin of coins) {
    if (remain === 0)
        break;

    count +=  Math.floor(remain / coin);
    remain %= coin;
}

console.log(count);