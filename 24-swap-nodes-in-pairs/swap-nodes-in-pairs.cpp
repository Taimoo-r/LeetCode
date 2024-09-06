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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        head = head->next;
        while (temp && temp->next) {
            ListNode* mid = temp->next;

            temp->next = temp->next->next;
            mid->next = temp;
            if(prev){
                prev->next = mid; 
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};