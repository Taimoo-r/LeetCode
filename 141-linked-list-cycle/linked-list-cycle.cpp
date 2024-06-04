class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *temp = head;
        std::unordered_map<ListNode*, bool> nodeSeen;
        while (temp != NULL) {
            // Check if we've seen this node before
            if (nodeSeen.find(temp) != nodeSeen.end()) {
                return true; // Cycle detected
            }
            // Mark this node as seen
            nodeSeen[temp] = true;
            temp = temp->next;
        }
        return false; // No cycle detected
    }
};