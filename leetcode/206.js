/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function (head) {
  const arr = [];
  while (head) {
    arr.push(head.val);
    head = head.next;
  }

  let list, tail;
  arr.reverse().forEach((v) => {
    if (!list) {
      list = new ListNode(v);
      tail = list;
    } else {
      tail.next = new ListNode(v);
      tail = tail.next;
    }
  });

  return list ? list : null;
};
