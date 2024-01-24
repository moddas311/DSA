class Stack
{

public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    Stack()
    {
    }

    int getSize()
    {
        return sz;
    }

    bool isEmpty()
    {
        return sz == 0;
    }

    void push(int data)
    {
        sz++;
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void pop()
    {
        if (isEmpty())
            return;
        sz--;
        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *tmp = head;
            while (tmp->next != tail)
            {
                tmp = tmp->next;
            }
            delete tail;
            tail = tmp;
            tail->next = NULL;
        }
    }
    int getTop()
    {
        if (!isEmpty())
        {
            return tail->data;
        }
        else
        {
            return -1;
        }
    }
};
