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
	vector<ListNode*> listes;

	void merge(int i, int j) {
		ListNode *prevA = new struct ListNode(0x80000000);
		ListNode *ptrA = listes[i];
		ListNode *ptrB = listes[j];
		ListNode *nextB;
		ListNode *headA = prevA;
		prevA->next = ptrA;
		while (ptrA != NULL && ptrB != NULL) {
			while (ptrA != NULL && ptrA->val < ptrB->val) {
				prevA = ptrA;
				ptrA = ptrA->next;
			}
			if (ptrA != NULL) {
				nextB = ptrB->next;
				prevA->next = ptrB;
				ptrB->next = ptrA;
				//next
				prevA = ptrB;
				ptrB = nextB;
			}
		}
		if (ptrB != NULL) {
			prevA->next = ptrB;
		}
		listes[i] = headA->next;
	}

	void partition(int l, int r) {
		if (l < r) {
			int mid = (r - l) / 2 + l;
			partition(l, mid);
			partition(mid + 1, r);
			merge(l, mid + 1);
		}
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) {
			return NULL;
		}
		this->listes = lists;
		partition(0, lists.size() - 1);
		return this->listes[0];
	}
};