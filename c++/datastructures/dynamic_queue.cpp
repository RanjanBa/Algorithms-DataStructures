#define dynamic_queue

namespace dynamicqueue
{
    template <typename T>
    class DynamicQueue
    {
    private:
        const int default_capacity;
        int capacity;
        int count;

        T *queue;

    public:
        DynamicQueue(int capacity = 10) : capacity(capacity), count(0), default_capacity(capacity)
        {
            queue = (T *)malloc(capacity * sizeof(T));
        }

        void push() {
            queue
        }

        T front() {}

        void pop()
        {
            if (isEmpty())
            {
            }
        }

        bool isEmpty() { return count == 0 }
        int size() { return count; }
        ~DynamicQueue() {}
    };
}