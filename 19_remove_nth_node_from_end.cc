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
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution
{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            if (head == NULL || n <= 0) return head;

            ListNode *cur, *nth, *dummy;
            dummy = cur = nth = new ListNode(0);
            dummy->next = head;

            for (int i = 0; i < n + 1; i++)
                cur = cur->next;

            while (cur != NULL) {
                cur = cur->next;
                nth = nth->next;
            }

            nth->next = nth->next->next;

            head = dummy->next;
            delete dummy;
            return head;
        }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    /*
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    */

    head = s.removeNthFromEnd(head, 1);
    ListNode* cur = head;
    while (cur != NULL) {
        cout << cur->val << endl;
        cur = cur->next;
    }

    return 0;
}
