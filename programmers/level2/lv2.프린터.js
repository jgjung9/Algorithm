// data = { data: , priority: }

class Queue {
    data;
    priority;
    size;
    constructor() {
        this.data = [];
        this.priority = [];
        this.size = 0;
    }
    push(x) {
        this.data.push(x);
        this.priority.push(x.priority);
        this.priority.sort((a, b) => b - a);
        this.size++;
    }
    shift(x) {
        if (this.data[0].priority === this.priority[0]) {
            this.priority.shift();
            this.size--;
            return this.data.shift();
        } else {
            this.data.push(this.data.shift());
        }
    }
}

function solution(priorities, location) {
    let answer = 0;
    const queue = new Queue();
    priorities.forEach((val, index) => {
        const data = {
            value: index,
            priority: val,
        };
        queue.push(data);
    });

    while (true) {
        const result = queue.shift();
        if (result) {
            answer++;
            if (result.value === location) {
                break;
            }
        }
    }

    return answer;
}

console.log(solution([1, 1, 9, 1, 1, 1], 0));

// [2, 1, 3, 2]	2	1
// [1, 1, 9, 1, 1, 1]	0	5
