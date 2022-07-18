/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
  let head, tail;
  let carry = 0;
  while (l1 || l2) {
    const v = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + carry;
    carry = Math.floor(v / 10);
    if (!head) {
      head = new ListNode(v % 10);
      tail = head;
    } else {
      tail.next = new ListNode(v % 10);
      tail = tail.next;
    }
    l1 = l1 ? l1.next : null;
    l2 = l2 ? l2.next : null;
  }
  if (carry) {
    tail.next = new ListNode(carry);
    tail = tail.next;
  }
  return head;
};
