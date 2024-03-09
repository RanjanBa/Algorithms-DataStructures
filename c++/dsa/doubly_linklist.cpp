#define dbly_link_list

namespace dblylinklist
{
    template <typename T>
    class Node
    {
    public:
        T value;
        Node<T> *next;
        Node<T> *prev;
        Node(T value) : value(value), next(nullptr), prev(nullptr) {}
        ~Node() {}
    };

    template <typename T>
    class DoublyLinkList
    {
    private:
        Node<T> *head;
        Node<T> *tail;

    public:
        DoublyLinkList() : head(nullptr), tail(nullptr) {}

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
            head->prev = node;
            head = node;
        }

        void pushBack(T value)
        {
            if (head == nullptr)
            {
                head = new Node<T>(value);
                tail = head;
                return;
            }

            Node<T> *node = new Node<T>(value);
            tail->next = node;
            node->prev = tail;
            tail = node;
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
            if (head != nullptr)
            {
                head->prev = nullptr;
            }

            delete cur;

            return val;
        }

        T popBack()
        {
            if (tail == nullptr)
            {
                throw tail;
            }

            T val = tail->value;
            Node<T> *cur = tail;

            tail = tail->prev;
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }

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
                        head->prev = nullptr;
                    }
                    else
                    {
                        prev->next = cur->next;
                        if (prev->next != nullptr)
                        {
                            prev->next->prev = prev;
                        }
                        else
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
            if (head == nullptr)
                return false;

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

        void printListReverse()
        {
            if (tail == nullptr)
                return;

            Node<T> *cur = tail;

            while (cur != nullptr)
            {
                cout << cur->value << " ";
                cur = cur->prev;
            }

            cout << endl;
        }

        ~DoublyLinkList() {}
    };
}
