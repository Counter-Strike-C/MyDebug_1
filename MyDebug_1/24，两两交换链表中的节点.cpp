#include "Common.cpp"
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}

//int main()
//{
//    ListNode* head = new ListNode(1);
//    ListNode* p = head;
//    p->next = new ListNode(2); p = p->next;
//    p->next = new ListNode(3); p = p->next;
//    p->next = new ListNode(4);
//
//    ListNode* p2 = head;
//    while (p2)
//    {
//        cout << p2->val << endl;
//        p2 = p2->next;
//    }
//
//    ListNode* p3 = swapPairs(head);
//    while (p3)
//    {
//        cout << p3->val << endl;
//        p3 = p3->next;
//    }
//
//    return 0;
//}