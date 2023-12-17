class Solution
{
public:
    void reverse(ListNode *&head, ListNode *current)
    {
        if (current->next == NULL)
        {
            head = current;
            return;
        }
        reverse(head, current->next);
        current->next->next = current;
        current->next = NULL;
    }
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return head;
        reverse(head, head);
        return head;
    }
};