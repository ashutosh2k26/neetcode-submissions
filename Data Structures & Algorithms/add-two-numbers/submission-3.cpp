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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = nullptr;
        int carry = 0;
        ListNode* pHead = root;
        ListNode* lt1 = l1;
        ListNode* lt2 = l2;
        bool isHead = true;

        while (lt1 != nullptr && lt2 != nullptr) {
            int v1 = lt1->val;
            int v2 = lt2->val;
            cout<<"v1-"<<v1<<" v2-"<<v2<<" carry "<<carry<<"\n";

            int s1 = v1 + v2 + carry;
            if (s1 >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            s1 = s1 % 10;
            ListNode* newNode = new ListNode(s1);
            if (isHead) {
                pHead = newNode;
                //cout << "Head" << pHead;
                root = pHead;
                isHead = false;
            } else {
                pHead->next = newNode;
                pHead = newNode;
            }
            lt1 = lt1->next;
            lt2 = lt2->next;
        }

        while (lt1 != nullptr) {
            int v1 = lt1->val;

            int s1 = v1 + carry;
            if (s1 >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            s1 = s1 % 10;
            ListNode* newNode = new ListNode(s1);
            if (isHead) {
                pHead = newNode;
                root = pHead;
                isHead = false;
            } else {
                pHead->next = newNode;
                pHead = newNode;
            }
            lt1 = lt1->next;
        }

        while (lt2 != nullptr) {
            int v1 = lt2->val;

            int s1 = v1 + carry;
            if (s1 >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            s1 = s1 % 10;
            ListNode* newNode = new ListNode(s1);
            if (isHead) {
                pHead = newNode;
                root = pHead;
                isHead = false;
            } else {
                pHead->next = newNode;
                pHead = newNode;
            }
            lt2 = lt2->next;
        }

        if (carry == 1) {
            ListNode* newNode = new ListNode(carry);
            pHead->next = newNode;
            pHead = newNode;
        }
        return root;
    }
};
