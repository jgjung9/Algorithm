function decimalToBinary(n) {
    let answer = "";
    while (n > 0) {
        answer += n % 2;
        n = Math.floor(n / 2);
    }
    return answer.split("").reverse().join("");
}

function solution(n, arr1, arr2) {
    const answer = [];

    for (let i = 0; i < n; i++) {
        let binary = decimalToBinary(arr1[i] | arr2[i]);
        for (let j = binary.length; j < n; j++) {
            binary = "0" + binary;
        }
        binary = binary.replace(/1/g, "#").replace(/0/g, " ");
        answer.push(binary);
    }
    return answer;
}

solution(6, [46, 33, 33, 22, 31, 50], [27, 56, 19, 14, 14, 10]);

// n	5
// arr1	[9, 20, 28, 18, 11]
// arr2	[30, 1, 21, 17, 28]
// 출력
// [
//   "#####",
//   "# # #",
//   "### #",
//   "# ##",
//   "#####"
// ]

// n	6
// arr1	[46, 33, 33 ,22, 31, 50]
// arr2	[27 ,56, 19, 14, 14, 10]
// 출력	["######", "### #", "## ##", " #### ", " #####", "### # "]
// [
//   "######",
//   "###  #",
//   "##  ##",
//   " #### ",
//   " #####",
//   "### # "
// ];
