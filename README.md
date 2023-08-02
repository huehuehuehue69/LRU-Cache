# LRU Cache Library

This library provides an implementation of an LRU (Least Recently Used) Cache in C++. The LRU Cache is a data structure that maintains a limited-size cache and evicts the least recently used items when the cache reaches its capacity.

## Classes

### `Node`

This class represents a node in the linked list used for implementing the LRU Cache. It contains the following members:

- `int key`: The key associated with the node.
- `int val`: The value associated with the node.
- `Node* prev`: Pointer to the previous node in the linked list.
- `Node* next`: Pointer to the next node in the linked list.

### `LRUCache`

This class implements the LRU Cache and contains the following members:

- `Node* head`: Pointer to the head sentinel node of the linked list.
- `Node* tail`: Pointer to the tail sentinel node of the linked list.
- `unordered_map<int, Node*> hash`: An unordered map to store the key-value pairs and their corresponding nodes in the linked list.
- `int capacity`: The maximum capacity of the LRU Cache.

### Constructor

- `LRUCache(int capacity)`: Initializes the LRU Cache with the given capacity.

### Methods

- `void insert(int key, int value)`: Inserts a new key-value pair into the LRU Cache. If the key already exists, it updates the value.
- `void deleteNode(int key)`: Deletes the node corresponding to the given key from the linked list and removes the key from the map.
- `int GET(int key)`: Retrieves the value corresponding to the given key from the LRU Cache. If the key exists, it marks the corresponding node as the most recently used by moving it to the front of the linked list.
- `void SET(int key, int value)`: Stores a new key-value pair in the LRU Cache. If the key already exists, it updates the value. If the cache has reached its capacity, it evicts the least recently used item.

## Usage

1. Include the "LRU-Cache.hpp" header file in your C++ code.
2. Create an instance of the `LRUCache` class with the desired capacity.
3. Use the `SET` and `GET` methods to manage and retrieve key-value pairs in the LRU Cache.

Example Usage:

```cpp
#include <iostream>
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
                int result = cache->GET(key);
                if (result == -1)
                {
                    cout << "NOT FOUND" << endl;
                }
                else
                {
                    cout << "The Value of Cache is " << result << endl;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
```

Note: The library provides an LRU Cache, and the example usage code demonstrates how to interact with the cache by setting and retrieving key-value pairs using the `SET` and `GET` methods. Ensure to handle memory management appropriately and free the dynamically allocated memory for the `LRUCache` object after use.
