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
 
 // <=================== MY SOLUTION & BEST SOLUTION ======================>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(--n && fast!=NULL){
            fast=fast->next;
        }

        if(fast->next == NULL){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        fast=fast->next;
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};




// <============== PROBLEM DESCRIPTION ===================>

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

//1: Example 

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
 

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
