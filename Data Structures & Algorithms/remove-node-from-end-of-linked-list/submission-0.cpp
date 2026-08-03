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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *last = head;
        int cnt = 1;
        while(cnt < n)
        {
            last = last -> next;
            cnt ++;
        }
        ListNode *curr = head;
        ListNode *prev = NULL;
        while(last && last -> next)
        {
            prev = curr;
            curr = curr -> next;
            last = last -> next;
        }
        if(curr == head)
            return head -> next;
        prev -> next = curr-> next;
        return head;
    }
};
