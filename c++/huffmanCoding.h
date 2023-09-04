#include <bits/stdc++.h>

using namespace std;

class Node
{
private:
    int freq;
    Node *p;
    Node *lf_child;
    Node *rt_child;

public:
    Node(int f)
    {
        freq = f;
        p = NULL;
        lf_child = NULL;
        rt_child = NULL;
    }

    Node(int f, Node *lf, Node *rt)
    {
        freq = f;
        p = NULL;
        lf->p = this;
        rt->p = this;
        lf_child = lf;
        rt_child = rt;
    }

    int frequency() { return freq; }

    Node *parent() { return p; }

    Node *leftChild() { return lf_child; }

    Node *rightChild() { return rt_child; }
};

string huffmanCode(string str)
{
    // unordered_map<char, int> mp;
    map<char, int> freq;

    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i]]++;
    }

    priority_queue<pair<int, Node *>> pq;

    map<char, Node *> mp;

    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        mp[it->first] = new Node(it->second);
        pq.push({(-1) * it->second, mp[it->first]});
    }

    Node *root;

    while (pq.size() > 1)
    {
        pair<int, Node *> a = pq.top();
        pq.pop();

        pair<int, Node *> b = pq.top();
        pq.pop();

        Node *left = a.second;
        Node *right = b.second;

        int cnt = a.first + b.first;
        Node *parent = new Node((-1) * cnt, left, right);

        pq.push({cnt, parent});

        root = parent;
    }

    string result = "";

    Node *nd = mp[str[3]];

    while (nd->parent() != NULL)
    {
        Node *p = nd->parent();

        if (nd == p->leftChild())
        {
            result = "0" + result;
        }
        else
        {
            result = "1" + result;
        }

        nd = p;
    }

    return result;
}