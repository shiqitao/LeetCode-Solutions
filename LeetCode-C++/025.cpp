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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 1) {
			return head;
		}
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *start = dummy;
		head = start;
		while (true) {
			int i;
			for (i = 0; i < k; i++) {
				if (head->next) {
					head = head->next;
				}
				else {
					break;
				}
			}
			if (i == k) {
				head = start->next;
				ListNode *pre = start;
				ListNode *next = head->next;
				for (int i = 0; i < k - 1; i++) {
					head->next = pre;
					pre = head;
					head = next;
					next = next->next;
				}
				head->next = pre;
				start->next->next = next;
				ListNode *temp = start->next;
				start->next = head;
				head = temp;
			}
			else break;
		}
		return dummy->next;
	}
};