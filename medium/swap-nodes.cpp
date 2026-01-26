#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    if (head->next == nullptr) {
      return head;
    } else {
      ListNode *next = swapPairs(head->next->next);
      ListNode *head_next = head->next;
      head->next = next;
      head_next->next = head;
      return head_next;
    }
  }
};
int main() {
  Solution sol;
  ListNode n1(1);
  n1.next = new ListNode(2);
  n1.next->next = new ListNode(3);
  n1.next->next->next = new ListNode(4);
  ListNode *n2 = sol.swapPairs(&n1);
  cout << n2->val << endl;
}
