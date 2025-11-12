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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1!=nullptr && p2!=nullptr){
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        while(p1 != nullptr) {
            cur1 = cur1->next;
            p1 = p1->next;
        }
        while(p2 != nullptr) {
            cur2 = cur2->next;
            p2 = p2->next;
        }

        while(cur1 != nullptr && cur2 != nullptr){
            if(cur1 == cur2) return cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
};



// <======= PROBLEM DESCRIPTION ========>
// 160. Intersection of Two Linked Lists
// Solved
// Easy

// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.