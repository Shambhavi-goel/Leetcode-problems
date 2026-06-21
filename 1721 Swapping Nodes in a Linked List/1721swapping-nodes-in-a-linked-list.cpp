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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* temp1= head;
        ListNode* temp3= head;
        int count=0;
        while(temp!= nullptr){
            count++;
            temp= temp->next;
        }
        
        int pos= count-k+1;
        for(int i=1; i< pos; i++){
            temp1= temp1->next;
        }
        int end_data= temp1->val;

        for(int i=1; i< k; i++){
            temp3= temp3->next;
        }
        int first_data= temp3->val;

        temp1->val= first_data;
        temp3->val= end_data;
        return head;

    }
};