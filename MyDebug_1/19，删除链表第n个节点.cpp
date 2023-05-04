#include "Common.cpp"

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

//Ë«Ö¸Õë½â·¨
ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* hh = new ListNode(0, head);
	ListNode* p1 = head;
	ListNode* p2 = hh;

	for (int i = 0; i < n; ++i)
		p1 = p1->next;

	while (p1)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	p2->next = p2->next->next;
	
	return hh->next;
}