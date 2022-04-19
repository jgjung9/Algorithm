const fs = require("fs");
const [N, K] = fs
  .readFileSync("./input.txt")
  .toString()
  .split(" ")
  .map((v) => +v);

class Node {
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}

class Queue {
  constructor(head, tail) {
    this.head = null;
    this.tail = null;
    this.size = 0;
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

const queue = new Queue();
let result = [];
for (let i = 1; i <= N; i++) {
  const node = new Node(i);
  queue.enqueue(node);
}

while (queue.size > 0) {
  for (let i = 0; i < K - 1; i++) {
    queue.enqueue(queue.dequeue());
  }
  result.push(queue.dequeue().data);
}

console.log(`<${result.join(", ")}>`);
