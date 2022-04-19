// 행렬 곲 a x b = c ( m x n matrix n x m matrix 곱)
// cij = ai1 * b1j + ai2 * b2j + ... ;
// cij = sigma k= 1 k->n  (aik + bkj) ;

const a = [
  [1, 2],
  [2, 4],
];

const b = [
  [1, 0],
  [0, 3],
];

function matrixMultiply(mat1, mat2) {
  let result = [];
  for (let i = 0; i < mat1.length; i++) {
    let row = [];
    for (let j = 0; j < mat2[0].length; j++) {
      let aij = 0;
      for (let k = 0; k < mat2.length; k++) {
        aij += mat1[i][k] * mat2[k][j];
      }
      row.push(aij);
    }
    result.push(row);
  }
  return result;
}

console.log(matrixMultiply(a, b));
