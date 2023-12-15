#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> web_address;
    string address;
    while (cin >> address)
    {
        if (address == "end")
        {
            break;
        }
        web_address.push_back(address);
    }

    auto current = web_address.begin();
    int query;
    cin >> query;
    while (query--)
    {
        string command;
        cin >> command;

        if (command == "visit")
        {
            string visit_address;
            cin >> visit_address;
            auto it = find(web_address.begin(), web_address.end(), visit_address);
            if (it != web_address.end())
            {
                current = it;
                cout << *current << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "next")
        {
            if (next(current) != web_address.end())
            {
                current++;
                cout << *current << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "prev")
        {
            if (current != web_address.begin())
            {
                current--;
                cout << *current << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }
    return 0;
}
