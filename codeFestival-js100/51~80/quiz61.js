function stringCompress(str) {
  let count = 1;
  let result = "";
  for (let i = 0; i <= str.length; i++) {
    let current = str[i];
    let next = str[i + 1];
    if (current === next) {
      count++;
    } else {
      result += `${current}${count}`;
      count = 1;
    }
    if (!next) {
      return result;
    }
  }
}

const str = prompt();
console.log(stringCompress(str));
