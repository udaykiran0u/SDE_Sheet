
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

 // <=================== How did i solve =========================>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int rem = 0;
        int u = 0, v = 0;
        while(l1!=nullptr && l2!=nullptr){
            u = l1->val;
            v = l2->val;
            int sum = u + v + rem;
            rem = sum/10;
            sum = sum%10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1!=nullptr){
            while(rem!=0 && l1!=nullptr){
                u = l1->val;
                int sum = u + rem;
                rem = sum/10;
                sum = sum%10;
                cur->next = new ListNode(sum);
                cur = cur->next;
                l1 = l1->next;
            }
            if(rem!=0) {
                cur->next = new ListNode(rem);
                cur = cur->next;    
            }
            cur->next = l1;
        }else{
            while(rem!=0 && l2!=nullptr){
                v= l2->val;
                int sum = v + rem;
                rem = sum/10;
                sum = sum%10;
                cur->next = new ListNode(sum);
                cur = cur->next;
                l2  = l2->next;
            }
            if(rem!=0) {
                cur->next = new ListNode(rem);
                cur = cur->next;    
            }
            cur->next = l2;
        }
        return dummy->next;
    }
};


// <===================== BEST SOLUTION ===============================>

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummy = new ListNode(0);
//         ListNode* curr = dummy;
//         int carry = 0;

//         while (l1 != nullptr || l2 != nullptr || carry != 0) {
//             int sum = carry;
//             if (l1 != nullptr) {
//                 sum += l1->val;
//                 l1 = l1->next;
//             }
//             if (l2 != nullptr) {
//                 sum += l2->val;
//                 l2 = l2->next;
//             }

//             carry = sum / 10;
//             curr->next = new ListNode(sum % 10);
//             curr = curr->next;
//         }

//         return dummy->next;
//     }
// };


// <========================= PROBLEM DESCRIPTION =============================>
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:


// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]