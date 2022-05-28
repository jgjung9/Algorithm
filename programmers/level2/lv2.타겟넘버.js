//BFS를 이용한 타겟 넘버 풀이
function solution(numbers, target) {
    let count = 0;

    const queue = [];
    let front = 0;
    let rear = 0;
    const d = [1, -1];
    function BFS(vertex, value) {
        for (let dir = 0; dir < 2; dir++) {
            const nextValue = value + d[dir] * numbers[vertex];
            if (vertex + 1 < numbers.length) {
                queue.push([vertex + 1, nextValue]);
                rear++;
            } else if (target === nextValue) count++;
        }
    }

    BFS(0, 0);
    while (front !== rear) {
        const [vertex, value] = queue[front++];
        BFS(vertex, value);
    }
    return count;
}

console.log(solution([4, 1, 2, 1], 4));
