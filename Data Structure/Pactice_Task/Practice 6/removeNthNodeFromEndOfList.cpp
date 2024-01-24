class Solution
{
public:
    int length(ListNode *head)
    {
        int count = 0;
        ListNode *tmp = head;
        while (tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = length(head);
        int del = size - n;
        ListNode *tmp = head;
        if (del == 0)
        {
            head = head->next;
        }
        else
        {
            for (int i = 1; i < del; i++)
            {
                tmp = tmp->next;
            }
            tmp->next = tmp->next->next;
        }
        return head;
    }
};