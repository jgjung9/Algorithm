// Merge Sort

function mergeSort(arr){
    if (arr.length <= 1){
      return arr;
    }
  
    const mid = Math.floor(arr.length / 2);
    const left = arr.slice(0,mid);
    const right = arr.slice(mid);
  
    return merge(mergeSort(left), mergeSort(right));
  }
  
  function merge(left, right){
    let result = [];
  
    while (/*빈칸을 채워주세요*/ && /*빈칸을 채워주세요*/){
      if (/*빈칸을 채워주세요*/){
        result.push(left.shift());
      } else {
        result.push(right.shift());
      }
    }
    while (left.length) {
      /*빈칸을 채워주세요*/
    }
    while (right.length) {
      /*빈칸을 채워주세요*/
    }
  
    return result;
  }
  
  const array = prompt('배열을 입력하세요').split(' ').map(n => parseInt(n, 10));
  
  console.log(mergeSort(array));