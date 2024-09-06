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
    ListNode* doubleIt(ListNode* head) {
        vector<long long> v;
        ListNode* temp = head;
        // long long res = 0;
        // while(temp){
        //     res*=10;
        //     res += temp->val;
        //     temp = temp->next;
        // }
        // res*=2;
        // string strNum = to_string(res);

        // ListNode* newHead = new ListNode(strNum[0] - 48);
        // ListNode* newTemp = newHead;
        // for(long long i = 1 ; i < strNum.size(); i++){
        //     newTemp->next = new ListNode(strNum[i]-48);
        //     newTemp = newTemp->next;
        // }
        // return newHead;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int carry = 0;
        bool addOne = false;
        vector<long long> doubled;
        for(int i = v.size()-1 ; i > -1 ; i--){
            int doubleValue =  v[i]*2 + carry;
            carry = doubleValue / 10;
            if(i==0 && carry){
                addOne = true;
            }
            if(carry){
                int rem = doubleValue % 10;
                v[i] = rem;
            }
            else{
                v[i] = doubleValue;
            }
        }
        if(addOne)
        v.insert(v.begin(), carry);

        ListNode* newHead = new ListNode(v[0]);
        ListNode* newTemp = newHead;
        for(long long i = 1 ; i < v.size(); i++){
            newTemp->next = new ListNode(v[i]);
            newTemp = newTemp->next;
        }
        return newHead;
    }
};