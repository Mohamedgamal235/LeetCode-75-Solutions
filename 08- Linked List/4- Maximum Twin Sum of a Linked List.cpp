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

    int pairSum(ListNode* head) {
        if (!head->next->next)
            return head->val + head->next->val;

        ListNode* slow = head ;
        ListNode* fast = head->next ;

        while (fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // here slow will stop on middel of list of nodes

        ListNode* reversedNode = reverseList(slow->next);
        slow = head ; 
        int ans = 0 ;
        while (reversedNode) {
            ans = max(ans , slow->val + reversedNode->val);
            slow = slow->next ;
            reversedNode = reversedNode->next ;
        }
        return ans ; 
    }
};