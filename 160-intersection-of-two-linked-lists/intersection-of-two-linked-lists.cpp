/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==headB)
        return headA;
        ListNode *temp = headB;
        while(headA){
            temp = headB;
            while(temp){
                if(headA==temp)
                return headA;
                else
                temp = temp->next;
            }
            headA = headA->next;
        }
        return nullptr;
    }
};