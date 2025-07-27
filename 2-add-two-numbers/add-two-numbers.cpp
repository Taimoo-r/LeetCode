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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;
        int car = 0;
        while(l1 || l2 || car){
            int a = l1 != nullptr ? l1->val : 0;
            int b = l2 != nullptr ? l2->val : 0;
            temp->next = new ListNode((a+b+car)%10);
            car = (a+b+car)/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            temp = temp->next;
        }
        return newHead->next;
    }
};