#include <bits/move.h>
#include <stddef.h>

#include "./ListNode.cpp"

using namespace std;

void reverse(ListNode<int> *&begin, ListNode<int> *&end) {
  ListNode<int> *it_prev = begin, *it = it_prev->next, *it_next = NULL;
  it_prev->next = end->next;

  while (it != NULL && it != begin->next) {
    it_next = it->next;
    it->next = it_prev;
    it_prev = it;
    it = it_next;
  }

  swap(begin, end);
}

ListNode<int> *solution(ListNode<int> *l, int k) {
  if (k < 2) {
    return l;
  }

  int count = 0;
  for (ListNode<int> *it = l, *begin = l, *end = NULL; (end = it) != NULL;
       it = end->next) {
    if (++count % k == 0) {
      if (begin == l) {
        reverse(l, end);
      } else {
        reverse(begin->next, end);
      }
      begin = end;
    }
  }

  return l;
}
