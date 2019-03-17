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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *start;
        ListNode *next;
        ListNode *prev;
        ListNode *node1;
        ListNode *node2;
        ListNode *mark;

        start = new struct ListNode(0);
        start->next = head;

        //设置标志结点，当交换起始点到此时便结束
        int len = 0;
        mark = head;
        while(head!=NULL) {
            len++;
            if(len%k==0) {
                mark = head->next;
            }
            head = head->next;
        }

        head = start;
        int i;
        while(start != NULL && start->next != mark) {
            i = 1;
            node1 = start->next;
            prev = node1;
            node2 = (node1!=NULL) ? node1->next : NULL;
            while(node2 != NULL && i<k) {
                next = node2->next;
                node2->next = node1;
                prev->next = next;
                start->next = node2;
                //next
                node1 = start->next;
                node2 = next;
                i++;
            }
            start = prev;
        }

        head = head->next;
        return head;
    }
};