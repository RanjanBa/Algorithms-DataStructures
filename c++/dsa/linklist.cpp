#define link_list

namespace linklist
{
    template <typename T>
    class Node
    {
    public:
        T value;
        Node<T> *next;

        Node(T value) : value(value), next(nullptr) {}
        ~Node() {}
    };

    template <typename T>
    class LinkList
    {
    private:
        Node<T> *head;
        Node<T> *tail;

    public:
        LinkList() : head(nullptr), tail(nullptr) {}

        void pushBack(T value)
        {
            if (head == nullptr)
            {
                head = new Node<T>(value);
                tail = head;
                return;
            }
            tail->next = new Node<T>(value);
            tail = tail->next;
        }

        void pushFront(T value)
        {
            if (head == nullptr)
            {
                head = new Node<T>(value);
                tail = head;
                return;
            }

            Node<T> *node = new Node<T>(value);
            node->next = head;
            head = node;
        }

        T popFront()
        {
            if (head == nullptr)
            {
                throw head;
            }

            T val = head->value;

            Node<T> *cur = head;
            head = head->next;

            delete cur;
            return val;
        }

        T popBack()
        {
            if (head == nullptr)
            {
                throw head;
            }

            Node<T> *cur = head, *prev = nullptr;
            while (cur->next != nullptr)
            {
                prev = cur;
                cur = cur->next;
            }

            if (prev != nullptr)
            {
                prev->next = nullptr;
                tail = prev;
            }
            else
            {
                head = nullptr;
                tail = nullptr;
            }

            T val = cur->value;
            delete cur;
            return val;
        }

        bool erase(T value)
        {
            if (head == nullptr || !isContain(value))
                return false;

            Node<T> *cur = head, *prev = nullptr;

            while (cur != nullptr)
            {
                if (cur->value == value)
                {
                    if (prev == nullptr)
                    {
                        head = cur->next;
                    }
                    else
                    {
                        prev->next = cur->next;
                        if (prev->next == nullptr)
                        {
                            tail = prev;
                        }
                    }

                    delete cur;
                    return true;
                }

                prev = cur;
                cur = cur->next;
            }

            return false;
        }

        bool isContain(T value)
        {
            Node<T> *cur = head;

            while (cur != nullptr)
            {
                if (cur->value == value)
                {
                    return true;
                }

                cur = cur->next;
            }

            return false;
        }

        void printList()
        {
            if (head == nullptr)
                return;
            Node<T> *cur = head;
            while (cur != nullptr)
            {
                cout << cur->value << " ";
                cur = cur->next;
            }

            cout << endl;
        }

        ~LinkList() {}
    };
}