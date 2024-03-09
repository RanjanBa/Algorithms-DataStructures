#define red_black_tree

namespace redblacktree
{
    template <typename T>
    class Node
    {
    public:
        T key;
        Node<T> *left, *right;

        Node(T key) : key(key), left(nullptr), right(nullptr) {}
        Node(T key, Node *left, Node *right) : key(key), left(left), right(right) {}
        ~Node() {}
    };

    template <typename T>
    class RedBlackTree
    {
    private:
        Node<T> *root;

    public:
        RedBlackTree() : root(nullptr) {}

        void insert(T key)
        {
            if (root == nullptr)
            {
                root = new Node<T>(key);
            }
        }

        void erase(T key)
        {
        }

        bool search(T key)
        {
            return false;
        }

        ~RedBlackTree() {}
    };
}
