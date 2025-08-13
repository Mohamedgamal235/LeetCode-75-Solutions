class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int len = 0 ;
        ListNode* temp = head ;
        while (temp) {
            len++ ;
            temp = temp->next ;
        }

        if (len == 1)
            return nullptr ;  

        ListNode* curr = head ;
        ListNode* prev = nullptr ;
        int middel = len / 2 ;

        int i = 0 ;
        while (i != middel) {
            i++ ;
            prev = curr ;
            curr = curr->next;
        }

        prev->next = curr->next ;
        delete curr ;
        return head ;
    }
};