const top = ["ABCDEF", "BCAD", "ADEFQRX", "BEDFG", "EFGHZ"];
const rule = "ABCD";

function check(top, rule) {
  let result = [];
  for (let i = 0; i < top.length; i++) {
    let bool = true;
    let search = rule.split("");

    for (let j = 0; j < rule.length; j++) {
      const str = top[i];
      let list = str.slice(str.indexOf(search.pop()));
      for (let k = 0; k < search.length; k++) {
        if (list.includes(search[k])) {
          bool = false;
          break;
        }
      }
      if (!bool) break;
    }

    if (bool) {
      result.push("가능");
    } else {
      result.push("불가능");
    }
  }
  return result;
}

console.log(check(top, rule));
