const fs = require("fs");
const input = +fs.readFileSync("./input.txt").toString().trim();

class Node {
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}

class linkedList {
  constructor() {
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
    const item = this.head;
    this.head = this.head.next;
    this.size--;
    return item;
  }
}

const list = new linkedList();

for (let i = 1; i <= input; i++) {
  const temp = new Node(i);
  list.enqueue(temp);
}

while (list.size > 1) {
  list.dequeue();
  const item = list.dequeue();
  item.next = null;
  list.enqueue(item);
}

console.log(list.head.data);
