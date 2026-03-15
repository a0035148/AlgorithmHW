#include <iostream>
#include <vector>
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0); // sorted list 的 dummy head
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* prev = &dummy;

            // 找到插入位置
            while (prev->next != NULL && prev->next->val < curr->val) {
                prev = prev->next;
            }

            ListNode* nextNode = curr->next;

            // 插入節點
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        return dummy.next;
    }
};