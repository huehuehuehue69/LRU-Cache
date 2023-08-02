#include <bits/stdc++.h>
#include "LRU-Cache.hpp"
using namespace std;

int main()
{
    int t;
    cout << "Enter No of TestCases." << endl;
    cin >> t;
    while (t--)
    {
        int capacity;
        cout << "Enter Capacity For Cache." << endl;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        int queries;
        cout << "Enter the number of Queries" << endl;
        cin >> queries;
        while (queries--)
        {
            cout << "Enter Query Type" << endl;
            cout << "SET For Setting the Value." << endl;
            cout << "GET for Getting the Value." << endl;
            string q;
            cin >> q;
            if (q == "SET")
            {
                cout << "Enter the key and Value." << endl;
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
                cout << "Value Setting Successfully" << endl;
            }
            else
            {
                cout << "Enter the Key." << endl;
                int key;
                cin >> key;
                if (cache->GET(key) == -1)
                {
                    cout << "NOT FOUND" << endl;
                    return;
                }
                cout << "The Value of Cache is " << cache->GET(key) << endl;
            }
        }
        cout << endl;
    }
    return 0;
}