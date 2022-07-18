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
var swapPairs = function (head) {
  let newHead = new ListNode();
  let tail = newHead;
  while (head) {
    let now = head;
    let next = head.next;
    head = next?.next;
    if (next) {
      now.next = next.next;
      next.next = now;
      tail.next = next;
    } else {
      tail.next = now;
    }
    tail = now;
  }
  return newHead.next;
};
