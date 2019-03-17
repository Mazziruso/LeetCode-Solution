#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //special case
        if(n==0) {
            return head;
        }
        int len = 0;
        ListNode *node = head;
        while(node!=NULL) {
            len++;
            node = node->next;
        }
        int index = len - n;
        node = head;
        ListNode *prev = new struct ListNode(0);
        prev->next = head;
        for(int i=0; i<index; i++) {
            node = node->next;
            prev = prev->next;
        }
        //delete
        prev->next = node->next;
        node->next = NULL;
        //delete head
        if(index==0) {
            head = prev->next;
        }
        return head;
    }
};