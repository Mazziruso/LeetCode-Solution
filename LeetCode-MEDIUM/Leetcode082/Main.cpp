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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev;
        ListNode *node1;
        ListNode *node2;

        int i;
        prev = new struct ListNode(0);
        prev->next = head;
        head = prev;
        while(prev != NULL) {
            node1 = prev->next;
            node2 = (node1!=NULL) ? node1->next : NULL;
            i = 0;
            while(node2!=NULL && node2->val==node1->val){
                node2 = node2->next;
                i++;
            }
            if(i>0) {
                prev->next = node2;
            } else {
                prev = prev->next;
            }
        }

        head = head->next;
        return head;
    }
};