#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *ptr;
        ListNode *ptr_tmp;
        ListNode *ptr_less;
        ListNode *pre;
        ListNode *next;

        ptr = head;
        ptr_less = new ListNode(0);
        ptr_less->next = head;
        pre = ptr_less;
        head = ptr_less;
        next = (ptr==NULL) ? NULL : ptr->next;
        while(ptr!=NULL) {
            if(ptr->val<x) {
                //delete
                ptr_tmp = ptr;
                pre->next = next;
                ptr = next;
                next = (ptr==NULL) ? NULL : ptr->next;
                //insert
                ptr_tmp->next = ptr_less->next;
                ptr_less->next = ptr_tmp;
                ptr_less = ptr_tmp;
                pre = ptr_less->next==ptr ? ptr_less : pre; //need to be concerned
            } else {
                pre = ptr;
                ptr = next;
                next = (ptr==NULL) ? NULL : ptr->next;
            }
        }
        return head->next;
    }
};