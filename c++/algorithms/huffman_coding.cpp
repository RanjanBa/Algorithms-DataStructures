#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
private:
    T key;
    int freq;

public:
    Node *parent;
    Node *lf_child;
    Node *rt_child;

    Node(int freq) : freq(freq), parent(nullptr), lf_child(nullptr), rt_child(nullptr) {}

    Node(T key, int freq) : key(key), freq(freq), lf_child(nullptr), rt_child(nullptr) {}

    T getKey() { return key; }

    int getFrequency() { return freq; }
};

Node<char> *buildHuffmanTree(unordered_map<char, int> &freq)
{
    priority_queue<pair<int, Node<char> *>, vector<pair<int, Node<char> *>>, greater<pair<int, Node<char> *>>> pq;

    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        Node<char>* tmp = new Node<char>(it->first, it->second);
        pq.push({it->second, tmp});
    }

    while (pq.size() > 1)
    {
        pair<int, Node<char> *> tp1 = pq.top();
        pq.pop();
        pair<int, Node<char> *> tp2 = pq.top();
        pq.pop();

        int f = tp1.first + tp2.first;

        Node<char> *node = new Node<char>(f);

        node->lf_child = tp1.second;
        node->rt_child = tp2.second;

        tp1.second->parent = node;
        tp2.second->parent = node;

        pq.push({f, node});
    }

    return pq.top().second;
}

void generateCodes(Node<char> *root, string res, unordered_map<char, string> &codes)
{
    if (root == nullptr)
        return;

    if (root->lf_child == nullptr && root->rt_child == nullptr)
    {
        codes[root->getKey()] = res;
        return;
    }

    generateCodes(root->lf_child, res + '0', codes);
    generateCodes(root->rt_child, res + '1', codes);
}

string generateEncoding(const unordered_map<char, string> &codes, string &str)
{
    string encoded = "";

    for (auto c : str)
    {
        if (codes.find(c) != codes.end())
        {
            encoded += codes.at(c);
        }
    }

    return encoded;
}

string decodeHuffman(Node<char> *root, string encoded_str)
{
    string res = "";

    Node<char> *cur = root;

    for (char c : encoded_str)
    {
        if (c == '0')
        {
            cur = cur->lf_child;
        }
        else
        {
            cur = cur->rt_child;
        }

        if (cur->lf_child == nullptr || cur->rt_child == nullptr)
        {
            res += cur->getKey();
            cur = root;
        }
    }

    return res;
}

void huffmanCodes(string data, string str)
{
    unordered_map<char, int> freq;

    for (int i = 0; i < data.size(); i++)
    {
        freq[data[i]]++;
    }

    Node<char> *root = buildHuffmanTree(freq);

    unordered_map<char, string> codes;
    generateCodes(root, "", codes);

    for (auto it : codes)
    {
        cout << it.first << " : " << it.second << endl;
    }
    
    string encoded_str = generateEncoding(codes, str);
    cout << "Encoded : " << encoded_str  << endl;

    string msg = decodeHuffman(root, encoded_str);
    cout << "Original msg : " << msg  << endl;
}

int main(int argc, char const *argv[])
{
    // string message = "aabbbbabbbcccdddeeeccceeeddeee";
    string message = "bbbbbbbbbccccccccccccdddddddddddddeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffffffffffffaaaaaggggg";

    huffmanCodes(message, "abaffcdeeeegaga");

    return 0;
}