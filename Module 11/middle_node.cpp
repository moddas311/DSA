class Solution
{
public:
    int size(ListNode *head)
    {
        ListNode *tmp = head;
        int count = 0;
        while (tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }
        return count;
    }
    ListNode *middleNode(ListNode *head)
    {
        ListNode *tmp = head;
        int sz = size(head);
        for (int i = 1; i <= sz / 2; i++)
        {
            tmp = tmp->next;
        }
        return tmp;
    }
};

// method - 2

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};