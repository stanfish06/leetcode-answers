class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode result(0);
        ListNode* ptr_result = &result;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                ptr_result->next = list1;
                list1 = list1->next;
            } else {
                ptr_result->next = list2;
                list2 = list2->next;
            }
            ptr_result = ptr_result->next;
        }
        ptr_result->next = list1 ? list1 : list2;
        return result.next;
    }
};
