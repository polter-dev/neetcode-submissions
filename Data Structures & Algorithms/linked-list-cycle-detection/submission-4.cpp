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
    bool hasCycle(ListNode* head) 
    {
        if (!head) return false;


        map<int, ListNode *> seen;

        while (head)
        {
            try {
                seen.at(head->val);
                if (seen.at(head->val) == head)
                    return true;
            } catch (std::out_of_range){
                seen[head->val] = head;
            }
            head = head->next;
        }

        return false;    
    }
};
