#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class ListNode;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode *head, *tail;
        head = tail = NULL;

        if (l1->val > l2->val) swap(l1, l2);
        head = tail = l1;
        l1 = l1->next;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }

        if (l1 != NULL) tail->next = l1;
        else tail->next = l2;

        return head;
    }
};

int main() {

    Solution s;

    ListNode *head1, *head2, *tail1, *tail2;

    head1 = tail1 = new ListNode(0);
    for (int i = 2; i < 10; i += 2) {
        tail1->next = new ListNode(i);
        tail1 = tail1->next;
    }

    head2 = tail2 = new ListNode(1);
    for (int i = 3; i < 10; i += 2) {
        tail2->next = new ListNode(i);
        tail2 = tail2->next;
    }
    
    cout << "d1" << endl;
    ListNode* head3 = s.mergeTwoLists(head1, head2);
    cout << "d2" << endl;

    while (head3 != NULL) {
        cout << head3->val << " ";
        head3 = head3->next;
    }
    cout << endl;
    return 0;
}
