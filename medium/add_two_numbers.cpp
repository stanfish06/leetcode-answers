/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr;
        ListNode* ptr_res = nullptr;
        int carry_over = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        while(l1 || l2) {
            if (l1) {
                a = l1->val;
                l1 = l1->next;
            } else {
                a = 0;
            }
            if (l2) {
                b = l2->val;
                l2 = l2->next;
            } else {
                b = 0;
            }
            c = (a + b + carry_over) % 10;
            carry_over = (a + b + carry_over) / 10;
            if (ptr_res == nullptr) {
                res = new ListNode(c);
                ptr_res = res;
            } else {
                ptr_res->next = new ListNode(c);
                ptr_res = ptr_res->next;
            }
        }
        if (carry_over == 1) {
            ptr_res->next = new ListNode(1);
        }
        return res;
    }
};
