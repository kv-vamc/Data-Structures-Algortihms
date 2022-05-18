/*
LC#21

You are given the heads of two sorted linked lists list1 and list2. Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
*/
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
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        //created dummy node to avoid edge case, when initially there will be no nodes.
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;

        while(list1 != NULL and list2 != NULL)
        {
            if(list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        //list1 still has nodes then link the list1 remaining nodes.
        if(list1)
            tail->next = list1;

        //list2 still has nodes then link the list2 remaining nodes.
        if(list2)
            tail->next = list2;        

        return dummy->next;
    }
};
