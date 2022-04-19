const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().split("\r\n");

const [N, M] = input[0].split(" ").map((value) => +value);

const Nlist = input.slice(1, N + 1);
const Mlist = input.slice(N + 1);

function solution(Nlist, Mlist) {
  const Nset = new Set(Nlist);
  const Mset = new Set(Mlist);
  const intersection = new Set(
    [...Nset].filter((item) => {
      if (Mset.has(item)) {
        return item;
      }
    })
  );
  console.log(intersection.size);
  console.log([...intersection].sort().join("\n"));
}

solution(Nlist, Mlist);
