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
        ListNode* o = head;
        int n = 0;
        while(o){
            n++;
            o = o->next;

        }
            k%=n;
        while (k--) {
            int containTwo = 0;
            ListNode* check = head;
            while (check) {
                check = check->next;
                containTwo++;
                if (containTwo > 2)
                    break;
            }
            if (containTwo > 2) {
                ListNode* temp = head->next;
                ListNode* currHead = head;
                ListNode* toRotate = head->next;

                while (temp->next->next) {
                    temp = temp->next;
                }
                toRotate = temp->next;
                temp->next = nullptr;
                ListNode* headNext = head;
                head = toRotate;
                head->next = headNext;
            }
            else if(containTwo == 2) {
                ListNode *first = head;
                ListNode *second = head->next;
                head = second;
                head->next = first;
                first->next = nullptr;
            }
            else
            return head;
        }
        return head;
    }
};