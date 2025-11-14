// <======= MY SOLUTION ==========>

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

    ListNode* reverseLinkedList(ListNode* head){
        if(head==nullptr || head->next==nullptr) return head;

        decltype(head) rev = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        decltype(head) cur = head;
        ListNode* dummy = nullptr;
        decltype(head) tailNode = nullptr;
        while(cur!=nullptr){
            int n = k;
            decltype(head) curHead = cur;
            while(--n && cur->next!=nullptr) cur = cur->next;
            if(n == 0) {
                ListNode* nextNode = cur->next;
                cur->next = nullptr;
                ListNode* rev = reverseLinkedList(curHead);
                if(tailNode!=nullptr) tailNode->next = rev;
                if(dummy==nullptr) dummy = rev;
                tailNode = curHead;
                cur = nextNode;
            }else{
                tailNode->next = curHead;
                return dummy;
            }
        }
        return dummy;
    }
};



// <>




// <======== PROBLEM DESCRIPTION =========>
// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:


// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
 

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000
 

// Follow-up: Can you solve the problem in O(1) extra memory space?