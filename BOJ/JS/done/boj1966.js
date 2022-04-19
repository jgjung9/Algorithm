const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().split("\r\n");
const testCase = +input.shift();

class Node {
  constructor(index, priority, next = null) {
    this.index = index;
    this.priority = priority;
    this.next = next;
  }
}

class Queue {
  constructor() {
    this.head = null;
    this.tail = null;
    this.priority = [];
    this.size = 0;
    this.count = 0;
  }

  enqueue(node) {
    if (this.head === null) {
      this.head = node;
    }
    if (this.tail === null) {
      this.tail = node;
    }
    this.tail.next = node;
    this.tail = node;
    this.size++;
  }

  dequeue() {
    const temp = this.head;
    this.head = this.head.next;
    temp.next = null;
    this.size--;
    return temp;
  }
}

for (let i = 0; i < testCase; i++) {
  const [N, M] = input
    .shift()
    .split(" ")
    .map((v) => +v);
  const priority = input
    .shift()
    .split(" ")
    .map((v) => +v);

  const queue = new Queue();
  for (let i = 0; i < N; i++) {
    const node = new Node(i, priority[i]);
    queue.enqueue(node);
  }
  queue.priority = priority.sort((a, b) => b - a);

  while (queue.size > 0) {
    const temp = queue.dequeue();
    if (temp.priority === queue.priority[0]) {
      queue.count++;
      queue.priority.shift();
      if (temp.index === M) {
        console.log(queue.count);
        break;
      }
    } else {
      queue.enqueue(temp);
    }
  }
}
