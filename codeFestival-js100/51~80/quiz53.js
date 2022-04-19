let str = prompt().split("");
let stack = [];
let boolean = true;

while (str.length > 0) {
  const data = str.pop();
  switch (data) {
    case "(":
      if (stack[stack.length - 1] !== ")") {
        boolean = false;
      } else {
        stack.pop();
      }
      break;
    case "[":
      if (stack[stack.length - 1] !== "]") {
        boolean = false;
      } else {
        stack.pop();
      }
      break;
    case "{":
      if (stack[stack.length - 1] !== "}") {
        boolean = false;
      } else {
        stack.pop();
      }
      break;
    default:
      stack.push(data);
      break;
  }
}

boolean && stack.length === 0 ? console.log("YES") : console.log("NO");

// let str = prompt().split("");
// let stack = [];
// let boolean = true;

// while (str.length > 0) {
//   const data = str.pop();
//   if (data === ")") {
//     stack.push(data);
//   } else if (data === "(" || stack.length <= 0) {
//     boolean = false;
//   } else {
//     stack.pop();
//   }

//   if (!boolean) {
//     break;
//   }
// }
// console.log(str);
// console.log(stack);

// boolean && stack.length === 0 ? console.log("YES") : console.log("NO");
