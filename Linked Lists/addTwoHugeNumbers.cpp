#include <stdexcept>
#include <string>

#include "./ListNode.cpp"

using namespace std;

string addTwoHugeNumbers(const string& a, const string& b) {
  try {
    return to_string(stoull(a) + stoull(b));
  } catch (out_of_range e) {
    string x = a, y = b;

    int N = x.size();

    if (y.size() > N) {
      N = y.size();
      x.insert(0, y.size() - x.size(), '0');
    } else if (y.size() < N) {
      y.insert(0, x.size() - y.size(), '0');
    }

    string ans = "";
    int carry = 0;

    for (int i = N - 1; i >= 0; --i) {
      int xi = x[i] - '0';
      int yi = y[i] - '0';
      string tmp = to_string(xi + yi + carry);

      if (i > 0) {
        if (tmp.size() > 1) {
          ans = tmp[1] + ans;
          carry = tmp[0] - '0';
        } else {
          ans = tmp[0] + ans;
          carry = 0;
        }
      } else {
        ans = tmp + ans;
      }
    }

    return ans;
  }
}

ListNode<int>* solution(ListNode<int>* a, ListNode<int>* b) {
  string x = "", y = "";

  for (ListNode<int>* it = a; it != NULL; it = it->next) {
    string s = to_string(it->value);
    x += s.insert(0, 4 - s.size(), '0');
  }

  for (ListNode<int>* it = b; it != NULL; it = it->next) {
    string s = to_string(it->value);
    y += s.insert(0, 4 - s.size(), '0');
  }

  string sum = addTwoHugeNumbers(x, y);

  ListNode<int>* ans = NULL;

  string el = "";
  for (int i = sum.size() - 1, cant = 0; i >= 0; i--) {
    cant++;
    el = sum[i] + el;
    if (cant == 4 || i == 0) {
      if (ans == NULL) {
        ans = new ListNode<int>(stoi(el));
      } else {
        ListNode<int>* new_el = new ListNode<int>(stoi(el));
        new_el->next = ans;
        ans = new_el;
      }
      cant = 0;
      el = "";
    }
  }

  return ans;
}
