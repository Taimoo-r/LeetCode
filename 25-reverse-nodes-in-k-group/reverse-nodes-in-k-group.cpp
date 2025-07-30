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
    ListNode* reverse(ListNode* head, int k, long i, int n){
        if(!head || i >= n+1) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int j = 1;
        while(curr && j <= k){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            j++;
            i++;
        }
        head->next = reverse(curr, k, i, n);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        }
        cout<<"SIZE : "<<n;
        int i = 1;
        return reverse(head, k, i, n-(n%k));
    }
};