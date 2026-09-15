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
        if(head == nullptr){
            return head;
        }
        ListNode* temp= head;
        temp= head-> next;
        ListNode* curr= head;
        ListNode* prev= head;
        while(temp != nullptr){
            if(temp-> val == curr-> val){
                ListNode* temporary= temp;
                prev->next= temp->next;
                temp= temp->next;
                delete temporary;
            }
            else{
            curr= temp;
            prev= temp;
            temp= temp->next;
            }
        }
        return head;
    }
};