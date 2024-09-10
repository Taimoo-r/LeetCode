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
    int gcd(int a, int b){
        if(b==0)
        return a;
        return gcd(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        ListNode *slow, *fast;
        while(temp && temp->next){
            ListNode* last = temp->next;
            int f = temp->val;
            int s = temp->next->val;
            int gd = gcd(max(f, s), min(f,s));
            temp->next = new ListNode(gd);
            temp = temp->next;
            temp->next = last;
            temp = temp->next; 
        }
        return head;
    }
};