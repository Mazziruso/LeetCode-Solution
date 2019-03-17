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
	ListNode* swapPairs(ListNode* head) {
		ListNode *node1 = head;
		ListNode *node2 = (node1!=NULL) ? head->next : NULL;
		ListNode *prev = new struct ListNode(0);
		prev->next = head;
		head = prev;
		while (node1 != NULL && node2 != NULL) {
			prev->next = node2;
			node1->next = node2->next;
			node2->next = node1;
			//next
			prev = node1;
			node1 = node1->next;
			node2 = (node1 != NULL) ? node1->next : NULL;
		}
		head = head->next;
		return head;
	}
};