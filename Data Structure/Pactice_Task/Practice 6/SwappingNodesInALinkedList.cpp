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

    ListNode *swapNodes(ListNode *head, int k)
    {
        int n = length(head);
        int front(k - 1);
        int back(n - k);
        ListNode *tmp = head;
        ListNode *tmp_2 = head;

        for (int i = 1; i <= front; i++)
        {
            tmp = tmp->next;
        }

        for (int i = 1; i <= back; i++)
        {
            tmp_2 = tmp_2->next;
        }
        swap(tmp->val, tmp_2->val);
        return head;
    }
};