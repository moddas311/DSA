class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
        {
            return head;
        }
        while (head != NULL && head->val == val)
        {
            head = head->next;
        }
        if (head == NULL)
        {
            return head;
        }
        ListNode *tmp = head;
        while (tmp->next != NULL)
        {
            if (tmp->next->val == val)
            {
                tmp->next = tmp->next->next;
            }
            else
            {
                tmp = tmp->next;
            }
        }
        return head;
    }
};