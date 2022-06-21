/**
 * https://www.acmicpc.net/problem/2661
 *
 * solution: 결정 문제으로 해결
 * 1, 2, 3 중 하나를 결정하고 다음으로 넘어간다
 * 결정한 값이 조건을 충족하지 못할경우 탈출 한다.
 */
const fs = require('fs');
const n = +fs.readFileSync('./input.txt').toString().trim();
const res = [];
const ans = [];
function check(res) {
  for (let i = 2; i <= res.length / 2; i++) {
    const right = res.slice(res.length - i);
    const left = res.slice(res.length - 2 * i, res.length - i);
    if (right.join() === left.join()) return false;
  }
  return true;
}

function go(n, idx) {
  if (!check(res)) return;
  if (n === idx) {
    ans.push(res.join(''));
    return;
  }

  for (let i = 1; i <= 3; i++) {
    if (res[res.length - 1] === i) continue;
    res.push(i);
    go(n, idx + 1);
    if (ans.length > 0) return;
    res.pop();
  }
}
go(n, 0);
console.log(ans[0]);
