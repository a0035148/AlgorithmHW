#include <iostream>
using namespace std;


struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: If the list is empty or has only one node, it is already sorted.
        if (!head || !head->next) {
            return head;
        }

        // Step 1: Split the list into two halves using the slow/fast pointer technique
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // Sever the connection between the two halves

        // Step 2: Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Step 3: Merge the sorted halves
        return merge(left, right);
    }

private:
    // Helper function to find the middle of the linked list
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Fast pointer moves twice as fast as the slow pointer
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // Slow pointer will be at the middle
    }

    // Helper function to merge two sorted linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Traverse both lists and attach the smaller value to the tail
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach any remaining nodes from either list
        if (list1) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;
    }
};