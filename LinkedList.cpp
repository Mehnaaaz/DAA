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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL) return NULL;
        if(head->next == NULL){
            // single node case:
            return head;
        }

        ListNode *current = head;

        while(current != NULL ){
            
            if( (current->next != NULL) && (current->val == current->next->val) ){
                // means duplicate milgya h delete krdenge current->next element ko
                ListNode *todelete = current->next;
                
                current->next = current->next->next;
                
                todelete->next = NULL;
                delete todelete;
            }
            else{
                // unequal case : current ko aage badhate jayenge!
                current = current->next;    // aage badhate jao               
            }
            
        }
        return head;        
    }
};