#include <stddef.h>

#include <vector>

#include "./ListNode.cpp"

using namespace std;

bool solution(ListNode<int> *l) {
  vector<int> v;

  for (ListNode<int> *it = l; it != NULL; it = it->next) {
    v.push_back(it->value);
  }

  for (int i = 0, j = v.size() - 1; i < j && i < v.size(); i++, j--) {
    if (v[i] != v[j]) {
      return false;
    }
  }

  return true;
}
