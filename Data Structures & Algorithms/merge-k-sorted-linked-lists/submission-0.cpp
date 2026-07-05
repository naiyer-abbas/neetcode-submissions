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
#define pin pair<int, ListNode*>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pin, vector<pin>, greater<pin>> pq;
        for(auto &node: lists)
        {
            if(node)
                pq.push({node -> val, node});
        }
        ListNode *head = NULL;
        ListNode *prev = NULL;
        while(!pq.empty())
        {
            ListNode *node = pq.top().second;
            pq.pop();
            if(node -> next)
                pq.push({node -> next -> val, node -> next});
            if(!head)
            {
                head = node;
                prev = head;
            }
            else
                prev -> next = node;
            prev = node;
        }
        return head;
    }
};
