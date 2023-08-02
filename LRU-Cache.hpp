#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    int val;
    Node *prev = NULL;
    Node *next = NULL;

    Node(int key, int value)
    {
        this->key = key;
        this->val = value;
    }
};
class LRUCache
{
private:
    Node *head;
    Node *tail;
    unordered_map<int, Node *> hash;
    int capacity;

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity)
    {
        hash.clear();
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void insert(int key, int value)
    {
        Node *temp = head->next;
        Node *node = new Node(key, value);
        head->next = node;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
        hash[key] = node;
    }

    void deleteNode(int key)
    {
        Node *temp = hash[key];
        Node *prevNode = temp->prev;
        Node *nextNode = temp->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        hash.erase(key);
    }
    // Function to return value corresponding to the key.
    int GET(int key)
    {
        if (hash.count(key))
        {
            int res = hash[key]->val;
            deleteNode(key);
            insert(key, res);
            return res;
        }
        return -1;
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        if (hash.count(key))
        {
            deleteNode(key);
        }
        if (hash.size() >= capacity)
        {
            deleteNode(tail->prev->key);
        }
        insert(key, value);
    }
};