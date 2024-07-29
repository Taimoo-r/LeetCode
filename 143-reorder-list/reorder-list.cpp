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
        if (!head || !head->next) return;

        stack<ListNode*> s;
        ListNode* put = head;
        while (put) {
            s.push(put);
            put = put->next;
        }

        ListNode* current = head;
        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            ListNode* tailNode = s.top();
            s.pop();

            ListNode* nextNode = current->next;
            current->next = tailNode;
            tailNode->next = nextNode;
            current = nextNode;
        }
        current->next = nullptr; // Make sure to end the list properly
    }
};