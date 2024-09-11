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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
            ListNode *temp = head;
            vector<int> v;
            while(temp){
                v.emplace_back(temp->val);
                temp = temp->next;
            }
            k%=v.size();
        while (k--) {
            int last = v.back();
            v.pop_back();
            v.insert(v.begin(), last);
        }
        ListNode* myhead = new ListNode(v[0]);
        ListNode* t = myhead;
        for(int i = 1 ; i < v.size() ; i++){
            t->next = new ListNode(v[i]);
            t = t->next;
        }
        return myhead;
    }
};