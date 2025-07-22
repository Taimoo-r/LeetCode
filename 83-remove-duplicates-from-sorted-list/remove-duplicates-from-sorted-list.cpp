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
    ListNode* helper(ListNode* head){
        if(head->next == nullptr) return head;

        ListNode* temp = helper(head->next);

        if(head->val == temp->val){
            if(temp->next){
                head->next = temp->next;
            } else head->next = nullptr;
        } 
        return head;

    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        return helper(head);
    }
};