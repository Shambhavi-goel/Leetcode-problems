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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;
        ListNode* temp1= head;
        ListNode* prev= nullptr;
        int count=0;
        while(temp!= nullptr){
            count++;
            temp= temp->next;
        }
        int pos;
        pos= (count/2)+1;

        if(head->next== nullptr){
            return nullptr;
        }
        for(int i=1; i<pos; i++){
            prev= temp1;
            temp1= temp1->next;
        }
        prev->next=temp1->next;
        delete temp1;
        return head;
    }
};