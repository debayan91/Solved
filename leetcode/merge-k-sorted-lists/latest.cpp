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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode* res = new ListNode(0);
        ListNode* r = res;

        for (int i = 0; i < size(lists); i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }

        while (!pq.empty()) {
            ListNode* p = pq.top();
            res->next = p;
            if(p->next) pq.push(p->next);
            p->next = NULL;
            res = res->next;
            pq.pop();
        }
        return r->next;
    }
};