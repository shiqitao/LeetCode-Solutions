/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int length = lists.size();
		ListNode *dummy = new ListNode(0);
		ListNode *head = dummy;
		while (true) {
			int index = -1;
			int min = INT_MAX;
			for (int i = 0; i < length; i++) {
				if (lists[i] != NULL && lists[i]->val < min) {
					min = lists[i]->val;
					index = i;
				}
			}
			if (index != -1) {
				head->next = lists[index];
				head = head->next;
				lists[index] = lists[index]->next;
			}
			else {
				break;
			}
		}
		return dummy->next;
	}
};