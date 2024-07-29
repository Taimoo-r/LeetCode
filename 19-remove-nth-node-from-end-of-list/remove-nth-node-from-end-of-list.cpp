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
        if(!head) return head;

        int size = 0;
        ListNode* Size = head;
        while(Size){
            size++;
            Size = Size->next;
        }
        cout<<size;
        if(n==size){
            return head->next;
        }
        ListNode* toRemove = head;
        for(int i = 1 ; i < size - n ; i++){
            toRemove = toRemove->next;
        }
        
            toRemove->next = toRemove->next->next;
        return head;
        
    }
};
