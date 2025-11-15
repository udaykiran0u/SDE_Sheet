## SOLUTION using recursion
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
    bool check(ListNode*& left,ListNode* right){
        if(right == nullptr) return true;

        if(!check(left,right->next)) return false;

        if(left->val != right->val) return false;
        left = left->next;
        return true;
    }

    bool isPalindrome(ListNode* head) {
        return check(head,head);
    }
};

## Solution using slow-fast(middle node) & reverse linkedlist
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return true;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* prev = nullptr;
    ListNode* current = slow;

    while (current != nullptr) {
        ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    ListNode* firstHalf = head;
    ListNode* secondHalf = prev;

    while (secondHalf != nullptr) {
        if (firstHalf->val != secondHalf->val)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}
};


# PROBLEM DESCRIPTION

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
![alt text](./../assets/image.png)
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?