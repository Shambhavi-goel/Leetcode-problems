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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* temp1= head;
        ListNode* prev= nullptr;
        int count=0;
        while(temp!= nullptr){
            count++;
            temp= temp->next;
        }
        if(n > count){
            return nullptr;
        }
        int pos= count-n+1;
        if(pos==1){
            head= temp1->next;
            delete temp1;
            return head;
        }
        for(int i=1; i< pos; i++){
            prev= temp1;
            temp1= temp1->next;
        }
        prev->next= temp1->next;
        delete temp1;
        return head;
 
    }
};