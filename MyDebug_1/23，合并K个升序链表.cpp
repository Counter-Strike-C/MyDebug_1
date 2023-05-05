#include "Common.cpp"

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list1;

    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
}

ListNode* merge(vector<ListNode*>& lists, int l, int r)
{
    if (l == r)return lists[l];        //到达子节点
    if (l > r)return nullptr;
    int mid = l + r >> 2;
    return mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    int l = 0;
    int r = lists.size()-1;

    return merge(lists, l, r);
}