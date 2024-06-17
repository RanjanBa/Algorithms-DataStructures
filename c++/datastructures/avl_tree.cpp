#define avl_tree

namespace avltree
{
    template <typename T>
    class Node
    {
    public:
        T key;
        int height;

        Node<T> *left, *right;
        Node(T key) : key(key), left(nullptr), right(nullptr)
        {
            height = 1;
        }

        Node(T key, Node *left, Node *right) : key(key), left(left), right(right)
        {
            height = 1;
        }
        ~Node() {}
    };

    template <typename T>
    class AVLTree
    {
    private:
        Node<T> *root;

        int max(int a, int b)
        {
            return a >= b ? a : b;
        }

        int getHeight(Node<T> *node)
        {
            if (node == nullptr)
                return 0;

            return node->height;
        }

        int getBalanceFactor(Node<T> *node)
        {
            if (node == nullptr)
                return 0;

            Node<T> *left = node->left;
            Node<T> *right = node->right;

            if (left == nullptr && right == nullptr)
            {
                return 0;
            }

            if (right == nullptr)
            {
                return left->height;
            }

            if (left == nullptr)
            {
                return (-1) * right->height;
            }

            return left->height - right->height;
        }

        Node<T> *getSuccessor(Node<T> *node)
        {
            if (node == nullptr)
                return node;

            if (node->right == nullptr)
            {
                return node;
            }

            Node<T> *cur = node->right;

            while (cur->left != nullptr)
            {
                cur = cur->left;
            }

            return cur;
        }

        Node<T> *getPredecessor(Node<T> *node)
        {
            if (node == nullptr)
            {
                return nullptr;
            }

            if (node->left == nullptr)
            {
                return node;
            }

            Node<T> *cur = node->left;

            while (cur->right != nullptr)
            {
                cur = cur->right;
            }

            return cur;
        }

        Node<T> *leftRotation(Node<T> *node)
        {
            if (node->right == nullptr)
                return node;

            Node<T> *right_child = node->right;
            Node<T> *right_left_child = node->right->left;

            right_child->left = node;
            node->right = right_left_child;

            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
            right_child->height = 1 + max(getHeight(right_child->left), getHeight(right_child->right));

            return right_child;
        }

        Node<T> *rightRotation(Node<T> *node)
        {
            if (node->left == nullptr)
                return node;

            Node<T> *left_child = node->left;
            Node<T> *left_right_child = node->left->right;

            left_child->right = node;
            node->left = left_right_child;

            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
            left_child->height = 1 + max(getHeight(left_child->left), getHeight(left_child->right));

            return left_child;
        }

        Node<T> *balanceTree(Node<T> *node, T key)
        {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));

            int factor = getBalanceFactor(node);

            if (factor > 1)
            {
                if (key < node->left->key)
                {
                    return rightRotation(node);
                }
                else if (key > node->left->key)
                {
                    node->left = leftRotation(node);
                    return rightRotation(node);
                }
            }
            else if (factor < -1)
            {
                if (key > node->right->key)
                {
                    return leftRotation(node);
                }
                else if (key < node->right->key)
                {
                    node->right = rightRotation(node->right);
                    return leftRotation(node);
                }
            }

            return node;
        }

        Node<T> *insertUtility(Node<T> *node, T key)
        {
            if (node == nullptr)
            {
                return new Node<T>(key);
            }

            if (key < node->key)
            {
                node->left = insertUtility(node->left, key);
            }
            else if (key > node->key)
            {
                node->right = insertUtility(node->right, key);
            }
            else
            {
                return node;
            }

            /*
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));

            int factor = getBalanceFactor(node);

            if (factor > 1)
            {
                if (key < node->left->key)
                {
                    return rightRotation(node);
                }
                else if (key > node->left->key)
                {
                    node->left = leftRotation(node);
                    return rightRotation(node);
                }
            }
            else if (factor < -1)
            {
                if (key > node->right->key)
                {
                    return leftRotation(node);
                }
                else if (key < node->right->key)
                {
                    node->right = rightRotation(node->right);
                    return leftRotation(node);
                }
            }

            return node;
            */

            return balanceTree(node, key);
        }

        Node<T> *eraseUtility(Node<T> *node, T key)
        {
            if (node == nullptr)
                return node;

            if (key < node->key)
            {
                node->left = eraseUtility(node->left, key);
            }
            else if (key > node->key)
            {
                node->right = eraseUtility(node->right, key);
            }
            else
            {
                if (node->left == nullptr)
                {
                    return node->right;
                }
                else if (node->right == nullptr)
                {
                    return node->left;
                }
                else
                {
                    Node<T> *tmp = getSuccessor(node);
                }
            }

            return balanceTree(node, key);
        }

        bool searchUtility(Node<T> *node, const T &key)
        {
            if (node == nullptr)
            {
                return false;
            }

            if (key == node->key)
            {
                return true;
            }

            if (key < node->key)
            {
                return searchUtility(node->left, key);
            }

            return searchUtility(node->right, key);
        }

        void preOrderUtility(Node<T> *node)
        {
            if (node == nullptr)
                return;

            cout << "(" << node->key << "," << node->height << ")" << endl;

            preOrderUtility(node->left);
            preOrderUtility(node->right);
        }

        void inOrderUtility(Node<T> *node)
        {
            if (node == nullptr)
                return;

            inOrderUtility(node->left);
            cout << "(" << node->key << "," << node->height << ")" << endl;
            inOrderUtility(node->right);
        }

    public:
        AVLTree() : root(nullptr) {}

        void insert(T key)
        {
            root = insertUtility(root, key);
        }

        void erase(T key)
        {
        }

        bool search(T key)
        {
            return false;
        }

        void preOrder()
        {
            preOrderUtility(root);
        }

        void inOrder()
        {
            inOrderUtility(root);
        }

        ~AVLTree() {}
    };
}