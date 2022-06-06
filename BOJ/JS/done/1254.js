/**
 * https://www.acmicpc.net/problem/1254
 */
const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim();
let ans = input.length;

function check(str) {
    const str2 = str.split('').reverse().join('');
    return str === str2 ? true : false;
}

for (let i = 0; i < input.length; i++) {
    if (check(input.slice(i))) {
        ans += i;
        break;
    }
}
console.log(ans);
