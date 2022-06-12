#include <stddef.h>

#include "./ListNode.cpp"

using namespace std;

ListNode<int> *solution(ListNode<int> *l, int n) {
  if (n == 0) {
    return l;
  }

  ListNode<int> *end = NULL;
  int size = 0;
  for (ListNode<int> *it = l; it != NULL; it = it->next) {
    size++;
    if (it->next == NULL) {
      end = it;
    }
  }

  if (size == n) {
    return l;
  }

  int count = size;
  ListNode<int> *begin = NULL;
  for (ListNode<int> *it = l; it != NULL; it = it->next, count--) {
    if (count - 1 == n) {
      begin = it;
    }
  }

  end->next = l;
  l = begin->next;
  begin->next = NULL;

  return l;
}
