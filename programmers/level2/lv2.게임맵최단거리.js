function solution(maps) {
  const n = maps.length;
  const m = maps[0].length;
  const visited = [];
  for (let i = 0; i < maps.length; i++) {
    const row = Array(maps[i].length).fill(-1);
    visited.push(row);
  }

  const dx = [0, 0, -1, 1];
  const dy = [-1, 1, 0, 0];
  const BFS = (x, y, depth) => {
    const queue = [];
    let front, rear;
    front = rear = 0;

    visited[x][y] = depth;
    queue.push([x, y, depth]);
    rear++;

    while (front != rear) {
      x = queue[front][0];
      y = queue[front][1];
      depth = queue[front][2];
      front++;

      for (let dir = 0; dir < 4; dir++) {
        const nextX = x + dx[dir];
        const nextY = y + dy[dir];
        if (nextX < 0 || nextX >= n) continue;
        if (nextY < 0 || nextY >= m) continue;
        if (maps[nextX][nextY] === 0) continue;
        if (visited[nextX][nextY] !== -1) continue;
        visited[nextX][nextY] = depth + 1;
        queue.push([nextX, nextY, depth + 1]);
        rear++;
      }
    }
  };

  BFS(0, 0, 1);
  return visited[n - 1][m - 1];
}
