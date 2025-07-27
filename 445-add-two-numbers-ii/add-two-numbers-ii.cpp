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
        if(!l1) return l2;
        if(!l2) return l1;
        if(!l1 && !l2) return nullptr;
        stack<int> st1, st2;
        while(l1){
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            st2.push(l2->val);
            l2 = l2->next;
        }
        vector<int> v;
        int carry = 0;
        while(!st1.empty() && !st2.empty()){
            int a = st1.top();
            st1.pop();
            int b = st2.top();
            st2.pop();
            v.push_back((a+b+carry)%10);
            carry = (a+b+carry)/10;
        }
        while(!st1.empty()){
            int a = st1.top();
            st1.pop();
            v.push_back((a+carry)%10);
            carry=(a+carry)/10;
        }
        while(!st2.empty()){
            int a = st2.top();
            st2.pop();
            v.push_back((a+carry)%10);
            carry=(a+carry)/10;
        }
        if(carry){
            v.push_back(carry);
        }
        ListNode* head = new ListNode();
        ListNode* temp = head;
        reverse(v.begin(), v.end());
        for(auto &it : v){
            temp->next = new ListNode(it);
            temp = temp->next;
        }
        return head->next;
        
    }
};