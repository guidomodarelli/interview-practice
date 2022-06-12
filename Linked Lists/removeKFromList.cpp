#include <stddef.h>

#include "./ListNode.cpp"

ListNode<int> *solution(ListNode<int> *l, int k) {
  if (l == NULL) {
    return l;
  }

  ListNode<int> *ans = l;

  while (ans != NULL && ans->value == k) {
    ans = ans->next;
  }

  ListNode<int> *it = ans;

  while (it != NULL && it->next != NULL) {
    if (it->next->value == k) {
      it->next = it->next->next;
    } else {
      it = it->next;
    }
  }

  return ans;
}
