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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>, greater<int>> p;
        for(int i = 0; i < lists.size(); i++){
            while(lists[i]){
                p.push(lists[i]->val);
                lists[i] = lists[i]->next; 
            }
        }
        ListNode* head = new ListNode;
        ListNode* temp = head;
        while(!p.empty()){
            temp->next = new ListNode(p.top());
            p.pop();
            temp = temp->next;
        }
        return head->next;
    }
};