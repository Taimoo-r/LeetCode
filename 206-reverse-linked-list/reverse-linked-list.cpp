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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        for(auto &it : v) cout<<it;
        ListNode* newHead = new ListNode(v.back());
        ListNode* temp = newHead;
        for(int i = v.size()-2 ; i >= 0 ; i--){
            cout<<v[i];
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return newHead;
    }
};