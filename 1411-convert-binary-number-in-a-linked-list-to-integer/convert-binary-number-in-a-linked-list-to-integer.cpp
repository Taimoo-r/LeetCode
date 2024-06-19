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
    int getDecimalValue(ListNode* head) {
        string nums;
        while(head){
            nums+=to_string(head->val);
            head = head->next;
        }
        int res = 0;
        int power = 0;
        for(int i = nums.size()-1;i > -1; i--){
            if(nums[i]=='0')
            power++;
            else if(nums[i]=='1'){
                res+=(pow(2,power++));
            }
        }
        return res;
    }
};