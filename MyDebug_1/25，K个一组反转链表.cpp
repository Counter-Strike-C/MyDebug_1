#include "Common.cpp"

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail)
{
    ListNode* prev = tail->next;
    ListNode* p = head;
    while (prev != tail)
    {
        ListNode* nex = p->next;
        p->next = prev;
        prev = p;
        p = nex;
    }
    return { tail,head };
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* hair = new ListNode(0);
    hair->next = head;
    ListNode* pre = hair;

    while (head)
    {
        ListNode* tail = pre;
        for (int i = 0; i < k; ++i)
        {
            tail = tail->next;
            if (!tail)   //如果尾巴为空，也就是长度没到k，就已经到链表尾部
            {
                return hair->next;
            }
        }

        ListNode* nex = tail->next;
        tie(head, tail) = myReverse(head, tail);

        pre->next = head;
        tail->next = nex;
        pre = tail;
        head =tail->next;

    }

    return hair->next;
}

