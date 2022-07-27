const solution = (p) => {
  // 1.
  if (p.length === 0) return p;

  // 2.
  let leftStr, rightStr, l, r;
  leftStr = '';
  l = r = 0;
  for (let x of p) {
    x === '(' ? l++ : r++;
    leftStr += x;
    if (l === r) {
      rightStr = p.slice(l + r);
      break;
    }
  }

  // 3, 4
  if (isRight(leftStr)) {
    // 3-1
    return (leftStr += solution(rightStr));
  } else {
    // 4-1 ~ 4-3
    let str = '(' + solution(rightStr) + ')';
    // 4-4 ~ 4-5
    leftStr = leftStr.slice(1, -1);
    for (let x of leftStr) {
      x === '(' ? (str += ')') : (str += '(');
    }
    return str;
  }
};

const isRight = (str) => {
  const stack = [];
  for (let x of str) {
    if (x === '(') stack.push(x);
    else if (x === ')' && stack.length > 0) stack.pop();
    else return false;
  }
  return true;
};

console.log(solution('(()())()'));
