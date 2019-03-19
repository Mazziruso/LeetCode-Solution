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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *start;
        ListNode *ptr;
        ListNode *pre;
        ListNode *next;

        start = new ListNode(0);
        start->next = head;
        ptr = head;
        head = start;

        int index = 1;
        while(index<m) {
            start = ptr;
            ptr = ptr->next;
            index++;
        }
        pre = ptr;
        ptr = ptr->next;
        next = (ptr==NULL) ? NULL : ptr->next;
        index++;
        while(index<=n) {
            ptr->next = pre;
            pre = ptr;
            ptr = next;
            next = (ptr==NULL) ? NULL : ptr->next;
            index++;
        }
        start->next->next = ptr;
        start->next = pre;

        return head->next;
    }
};

int main() {

    vector<int> vals({1,2,3,4,5});
    ListNode *head = new ListNode(vals[0]);
    ListNode *ptr = head;
    for(int i=1; i<vals.size(); i++) {
        ptr->next = new ListNode(vals[i]);
        ptr = ptr->next;
    }

    Solution().reverseBetween(head, 2, 4);

    return 0;
}