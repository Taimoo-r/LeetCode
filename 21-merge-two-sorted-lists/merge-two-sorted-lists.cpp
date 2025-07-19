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
        if(list2 && !list1) return list2;
        if(list1 && !list2) return list1;
        ListNode dummy;
        ListNode* temp = &dummy;
        int i = 0;
        while(list1 && list2){
            cout<<++i;
            if(list1->val > list2->val){
                temp->next = list2;
                list2 = list2->next;
            }
            else {
                temp->next = list1;
                list1 = list1->next;
            }
            temp = temp->next;

        }
        temp->next = list1 ? list1 : list2;
        return dummy.next;
        
    }
};