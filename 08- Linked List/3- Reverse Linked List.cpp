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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head ;
        ListNode* curr = head->next ;
        ListNode* prev = nullptr;
        while (curr) {
            head->next = prev ;
            prev = head ;
            head = curr ;
            curr = curr->next;
        }
        head->next = prev ;
        return head ;
    }
};