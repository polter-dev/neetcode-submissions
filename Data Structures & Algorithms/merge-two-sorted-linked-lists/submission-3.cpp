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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if (!list1 && !list2) return NULL;
        if (!list1) return list2;
        if (!list2) return list1;
        
        ListNode *ret;
        ListNode *walker1 = list1, *walker2 = list2;

        if (walker1->val < walker2->val)
        {
            ret = walker1;
            walker1 = walker1->next;
        }
        else
        {
            ret = walker2;
            walker2 = walker2->next;
        }

        ListNode *newHead = ret;
        
        while(walker1 && walker2) 
        {
            if (walker2->val < walker1->val)
            {
                ret->next = walker2;
                walker2 = walker2->next;
                ret = ret->next;
            }
            else
            {
                ret->next = walker1;
                ret = ret->next;
                walker1 = walker1->next;
            }

        }

        if (walker1)
            ret->next = walker1;
        else if (walker2)
            ret->next = walker2;

        return newHead;
    }
};
