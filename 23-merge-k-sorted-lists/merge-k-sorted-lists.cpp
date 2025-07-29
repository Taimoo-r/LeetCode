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
struct compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(auto &it : lists){
            if(it) pq.push(it);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* end = dummy;
        while(!pq.empty()){
            end->next = pq.top();
            pq.pop();
            end = end->next;
            if(end->next){
                pq.push(end->next);
            }
        }
        return dummy->next;
    }
};