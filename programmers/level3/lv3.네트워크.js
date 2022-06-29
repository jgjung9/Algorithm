function solution(n, computers) {
  let answer = 0;
  const visited = Array(n).fill(false);
  const DFS = (node) => {
    visited[node] = true;

    for (let i = 0; i < n; i++) {
      const nextNode = i;
      if (computers[node][nextNode] === 0) continue;
      if (visited[nextNode]) continue;
      DFS(nextNode);
    }
  };

  for (let i = 0; i < n; i++) {
    if (!visited[i]) {
      DFS(i);
      answer++;
    }
  }
  return answer;
}

console.log(
  solution(3, [
    [1, 1, 0],
    [1, 1, 0],
    [0, 0, 1],
  ])
);
