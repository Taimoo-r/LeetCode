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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp = list1;
        vector<int> v;
        while(temp){
            v.emplace_back(temp->val);
            temp = temp->next;
        }
        temp = list2;
        while(temp){
            v.emplace_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(),v.end());
        ListNode *head = nullptr;
        ListNode *curr = head;
        for(int i=0;i<v.size();i++){
            if(i==0){
                head = new ListNode(v[i]);
                curr = head;
            }
            else{
                curr->next = new ListNode(v[i]);
                curr = curr->next;
            }

        }
        return head;
    }
};