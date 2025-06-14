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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minhump(cmp);
        
        for(auto node : lists) if(node) minhump.push(node);

        ListNode dumdum(0);
        ListNode* ending = &dumdum;

        while(!minhump.empty()){
            ListNode* node = minhump.top();
            minhump.pop();
            ending->next = node;
            ending = ending->next;
            if(node->next) minhump.push(node->next);
        }
        return dumdum.next;
    }
};