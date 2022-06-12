#include <stddef.h>

#include "./ListNode.cpp"

void push_back(ListNode<int> *&ans, ListNode<int> *&tail, const int &value) {
  ListNode<int> *new_el = new ListNode<int>(value);
  if (ans == NULL) {
    ans = new_el;
    tail = ans;
  } else {
    tail->next = new_el;
    tail = new_el;
  }
}

ListNode<int> *solution(ListNode<int> *l1, ListNode<int> *l2) {
  ListNode<int> *ans = NULL, *tail = NULL;

  ListNode<int> *it = l1, *it2 = l2;

  while (it != NULL || it2 != NULL) {
    if (it != NULL && it2 != NULL) {
      if (it->value < it2->value) {
        push_back(ans, tail, it->value);
        it = it->next;
      } else {
        push_back(ans, tail, it2->value);
        it2 = it2->next;
      }
    } else if (it != NULL) {
      push_back(ans, tail, it->value);
      it = it->next;
    } else {
      push_back(ans, tail, it2->value);
      it2 = it2->next;
    }
  }

  return ans;
}
