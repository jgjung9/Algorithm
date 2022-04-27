function move(matrix, x, y, pre) {
    let temp = matrix[x][y];
    matrix[x][y] = pre;
    pre = temp;
    return pre;
}

function solution(rows, columns, queries) {
    const answer = [];
    const matrix = [];
    for (let i = 0; i < rows; i++) {
        const row = [];
        for (let j = 0; j < columns; j++) {
            row.push(j + 1 + i * columns);
        }
        matrix.push(row);
    }

    let posX, posY;

    for (let x of queries) {
        const [x1, y1, x2, y2] = x;
        posX = x1 - 1;
        posY = y1;
        let pre = matrix[posX][posY - 1];
        let min = pre;
        // 우
        while (posY < y2) {
            pre = move(matrix, posX, posY, pre);
            min = Math.min(min, pre);
            posY++;
        }
        posY--;
        posX++;

        // 하
        while (posX < x2) {
            pre = move(matrix, posX, posY, pre);
            min = Math.min(min, pre);
            posX++;
        }
        posX--;
        posY--;

        // 좌
        while (posY >= y1 - 1) {
            pre = move(matrix, posX, posY, pre);
            min = Math.min(min, pre);
            posY--;
        }
        posY++;
        posX--;

        // 상
        while (posX >= x1 - 1) {
            pre = move(matrix, posX, posY, pre);
            min = Math.min(min, pre);
            posX--;
        }
        answer.push(min);
    }
    return answer;
}

console.log(
    solution(3, 3, [
        [1, 1, 2, 2],
        [1, 2, 2, 3],
        [2, 1, 3, 2],
        [2, 2, 3, 3],
    ])
);

// 6	6	[[2,2,5,4],[3,3,6,6],[5,1,6,3]]	[8, 10, 25]
// 3	3	[[1,1,2,2],[1,2,2,3],[2,1,3,2],[2,2,3,3]]	[1, 1, 5, 3]
// 100	97	[[1,1,100,97]]	[1]
