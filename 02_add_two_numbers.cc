#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        /**
         * Pseudo code
         *
         * // assume that if one of the lists is smaller then the other,
         * // it returns 0 during rest iteration
         * for each i1, i2 in l1, l2 do
         *     val = ii + i2;
         *     if val >= 10 then
         *         push val-10 ahead of l
         *         carry = 1
         *     else then
         *         push val ahead of l
         *         carry = 0
         *
         */
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

            if (!l1) return (l2);
            if (!l2) return (l1);

            int i1, i2, c, v;
            ListNode *head, *cur;
            head = cur = NULL;
            c = 0;
            
            while (!l1 || !l2) {
                i1 = l1 == NULL? 0 : l1->val;
                i2 = l2 == NULL? 0 : l2->val;
                v = i1 + i2 + c;
               
                ListNode *n = new ListNode(0);
                if (cur == NULL) {
                    head = cur = n;
                } else {
                    cur->next = n;
                    cur = cur->next;
                }

                if (v >= 10) {
                    cur->val = v - 10;
                    c = 1;
                } else {
                    cur->val = v;
                    c = 0;
                }
                l1 = l1 == NULL? NULL: l1->next;
                l2 = l2 == NULL? NULL: l2->next;
            }

            if (c == 1) 
                cur->next = new ListNode(1);

            return head;
        }
};


int main() {
    Solution s;
    ListNode *l1, *l2;
    l1 = new ListNode(5);
    
    l2 = new ListNode(5);

    ListNode *l = s.addTwoNumbers(l1, l2);
    while (l != NULL) {
        cout << l->val << endl;
        l = l->next;
    }
    return 0;
}
