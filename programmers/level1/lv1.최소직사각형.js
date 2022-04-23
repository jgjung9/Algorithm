// 어렵게 생각했으나 단순하게 두개의 명함을 비교했을 때 최소 크기를 결정하면
// 그 크기는 그 두 명함을 넣기 위해서는 반드시 필요한 크기가 된다.
// 따라서 그 크기를 하나의 명함 사이즈로 생각하고 다시 다음 명함과 비교하면서 새롭게 명함사이즈 크기를 맞추면
// 최종적으로 결정되는 명함사이즈가 결정 모든 명함을 담을 수 있는 최소 사이즈가 된다.

function solution(sizes) {
  let width = (height = Number.MIN_SAFE_INTEGER);
  for (const size of sizes) {
    const curWidth = Math.max(...size);
    const curHeight = Math.min(...size);

    if (width < curWidth) {
      width = curWidth;
    }

    if (height < curHeight) {
      height = curHeight;
    }
  }
  return width * height;
}

solution([
  [60, 50],
  [30, 70],
  [60, 30],
  [80, 40],
]);

// [[60, 50], [30, 70], [60, 30], [80, 40]]	4000
// [[10, 7], [12, 3], [8, 15], [14, 7], [5, 15]]	120
// [[14, 4], [19, 6], [6, 16], [18, 7], [7, 11]]	133
