#include <bits/stdc++.h>
using namespace std;

// students details class
class Students
{
public:
    string name;
    int roll;
    int marks;

    Students(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

// custom compare

class studetsCmp
{
public:
    bool operator()(Students a, Students b)
    {
        
        if (a.marks < b.marks)
        {
            return true;
        }
        else if (a.marks > b.marks)
        {
            return false;
        }

        else
        {
            if (a.roll > b.roll)
            {
                return true;
            }
            else
                return false;
        }
    }
};
int main()
{
    int n;
    cin >> n;

    priority_queue<Students, vector<Students>, studetsCmp> studentsQ;

    for (int i = 0; i < n; i++)
    {
        string name;
        int roll;
        int marks;
        cin >> name >> roll >> marks;

        Students obj(name, roll, marks);
        studentsQ.push(obj);
    }

    int Query;
    cin >> Query;
    while (Query--)
    {
        int command;
        cin >> command;
        if (command == 0)
        {
            string name;
            int roll;
            int marks;
            cin >> name >> roll >> marks;
            Students x(name, roll, marks);
            studentsQ.push(x);
            cout << studentsQ.top().name << " " << studentsQ.top().roll << " " << studentsQ.top().marks << endl;
        }
        else if (command == 1)
        {
            if (!studentsQ.empty())
                cout << studentsQ.top().name << " " << studentsQ.top().roll << " " << studentsQ.top().marks << endl;
            else
                cout << "Empty" << endl;
        }

        else if (command == 2)
        {
            if (!studentsQ.empty())
            {
                studentsQ.pop();
                if (!studentsQ.empty())
                    cout << studentsQ.top().name << " " << studentsQ.top().roll << " " << studentsQ.top().marks << endl;
                else
                    cout << "Empty" << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
    }
    return 0;
}