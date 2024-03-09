template <typename T>
class Node
{
private:
    T key;
    Node *left, *right;

public:
    Node(T key)
    {
        this->key = key;
        left = nullptr;
        right = nullptr;
    }
    Node(T key, Node *left, Node *right)
    {
        this->key = key;
        this->left = left;
        this->right = right;
    }
    ~Node() {}
};
