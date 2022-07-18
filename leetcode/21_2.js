/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function (list1, list2) {
  let head, tail;
  const arr = [];
  while (list1) {
    arr.push(list1.val);
    list1 = list1.next;
  }
  while (list2) {
    arr.push(list2.val);
    list2 = list2.next;
  }
  arr.sort((a, b) => a - b);
  arr.forEach((v) => {
    const newNode = new ListNode(v, null);
    if (!head) {
      head = newNode;
      tail = head;
    } else {
      tail.next = newNode;
      tail = tail.next;
    }
  });
  return head ? head : null;
};
