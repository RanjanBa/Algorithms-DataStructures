class Node
{
private:
    int key;
    Node* left, *right;
public:
    Node(int key);
    Node(int key, Node* left, Node* right);
    ~Node();
};

Node::Node(int key)
{
    this->key = key;
    left = nullptr;
    right = nullptr;
}

Node::Node(int key, Node* left, Node* right) {
    this->key = key;
    this->left = left;
    this->right = right;
}

Node::~Node()
{
}
