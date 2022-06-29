function solution(n, edge) {
  let cnt = 0;
  const graph = [];
  for (let i = 0; i <= n; i++) {
    const row = [];
    graph.push(row);
  }

  edge.forEach((e) => {
    const [u, v] = e;
    graph[u].push(v);
    graph[v].push(u);
  });
  const visited = Array(n + 1).fill(-1);
  let max = 0;

  const BFS = (node, depth) => {
    const queue = [];
    let front, rear;
    front = rear = 0;

    visited[node] = depth;
    queue.push([node, depth]);
    rear++;

    while (front != rear) {
      node = queue[front][0];
      depth = queue[front][1];
      front++;

      for (let i = 0; i < graph[node].length; i++) {
        const nextNode = graph[node][i];
        if (visited[nextNode] !== -1) continue;
        visited[nextNode] = depth + 1;
        queue.push([nextNode, depth + 1]);
        rear++;
        if (depth + 1 > max) max = depth + 1;
      }
    }
  };

  BFS(1, 0);
  visited.forEach((v) => {
    if (v === max) cnt++;
  });

  return cnt;
}
