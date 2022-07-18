/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function (head) {
  let node = head;
  const list = [];
  while (node !== null) {
    list.push(node.val);
    node = node.next;
  }
  let lp = 0;
  let rp = list.length - 1;

  while (lp < rp) {
    if (list[lp++] !== list[rp--]) {
      return false;
    }
  }
  return true;
};
