#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL) {
            return;
        }
        vector<ListNode*> stack;
        ListNode *node=head;
        while(node!=NULL) {
            stack.push_back(node);
            node = node->next;
        }
        int left = stack.size()/2-1;
        int right = (stack.size()+1)/2;
        if((stack.size()&1)==0) {
            stack[right]->next = NULL;
            left--;
            right++;
        } else{
            stack[left+1]->next = NULL;
        }
        while(left>=0 && right<stack.size()) {
            stack[left]->next = stack[right];
            stack[right]->next = stack[left+1];
            left--;
            right++;
        }
    }
};

class Solution_constSpace {
public:
    void reorderList(ListNode* head) {
        ListNode *ptr1 = head;
        ListNode *ptr2 = (head==NULL) ? NULL : head->next;
        
        //find mid
        while(ptr2 && ptr2->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            ptr2 = (ptr2==NULL) ? NULL : ptr2->next;
        }

        //cut first half and right half, reverse
        ListNode *headR = NULL;
        if(ptr1!=NULL) {
            headR = ptr1->next;
            ptr1->next = NULL;
        }
        if(headR!=NULL) {
            ptr2 = headR->next;
            headR->next = NULL;
        }
        while(ptr2) {
            ptr1 = ptr2->next;
            ptr2->next = headR;
            headR = ptr2;
            ptr2 = ptr1;
        }

        //merge
        ptr1 = head;
        ptr2 = headR;
        while(ptr1 && ptr2) {
            headR = ptr1->next;
            ptr1->next = ptr2;
            ptr2 = ptr2->next;
            ptr1->next->next = headR;
            ptr1 = headR;
        }
    }
};

int main() {

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);

    Solution_constSpace().reorderList(NULL);

    return 0;
}