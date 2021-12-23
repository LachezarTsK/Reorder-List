
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    //Find middle node.
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //Reverse nodes in the second part, starting from the middle.
        ListNode* current = slow;
        ListNode* previous = nullptr;
        ListNode* temp;
        while (current != nullptr) {
            temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        delete current;

        //Combine the nodes of the first and second part, in alternating manner.
        ListNode* odd = head;
        ListNode* even = previous;
        while (even->next != nullptr) {
            temp = odd->next;
            odd->next = even;
            odd = temp;

            temp = even->next;
            even->next = odd;
            even = temp;
        }
    }
};
