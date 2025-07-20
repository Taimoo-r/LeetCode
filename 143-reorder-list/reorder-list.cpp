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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp){
            st.push(temp);
            temp = temp->next;
        }
        ListNode* t = head;
        int n = st.size();
        for(int i = 0 ; i < n/2 ; i++){
            ListNode* next = t->next;
            t->next = st.top();
            st.pop();
            t = t->next;
            t->next = next;
            t = next;
        }
         t->next = nullptr;
        
    }
};