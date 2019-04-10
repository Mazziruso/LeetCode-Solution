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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head==NULL ? NULL : head->next;
        ListNode *fast = slow==NULL ? NULL : slow->next;
        
        while(fast!=NULL && slow!=NULL && fast!=slow) {
            slow = slow->next;
            fast = fast==NULL ? NULL : fast->next;
            fast = fast==NULL ? NULL : fast->next;
        }

        return (fast!=NULL && slow!=NULL);
    }
};