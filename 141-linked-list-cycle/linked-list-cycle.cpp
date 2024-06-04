class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *temp = head;
        unordered_map<ListNode*, bool> nodeSeen;
        while (temp != NULL) {
            if (nodeSeen.find(temp) != nodeSeen.end()) {
                return true; 
            }
            nodeSeen[temp] = true;
            temp = temp->next;
        }
        return false;
    }
};