#define dynamic_stack

namespace dynamicstack
{
    template <typename T>
    class DynamicStack
    {
    private:
        T *stack;
        const int default_capacity;
        int count;
        int capacity;

        void copyStack(int new_capacity)
        {
            if (new_capacity < default_capacity)
                return;

            capacity = new_capacity;
            T *new_stack = (T *)malloc(capacity * sizeof(T));

            for (int i = 0; i < count; i++)
            {
                new_stack[i] = stack[i];
            }

            stack = new_stack;
        }

    public:
        DynamicStack(int capacity = 10) : capacity(capacity), count(0), default_capacity(capacity) {}

        void push(T value)
        {
            if (count == capacity)
            {
                copyStack(2 * capacity);
            }

            stack[count++] = value;
        }

        T top()
        {
            return stack[count - 1];
        }

        void pop()
        {
            if (count == 0)
            {
                throw std::runtime_error("Can't pop empty stack!");
            }

            count--;
            if (count < capacity / 2)
            {
                copyStack(capacity / 2);
            }
        }

        bool isEmpty()
        {
            return count == 0;
        }

        int size()
        {
            return count;
        }

        ~DynamicStack() {}
    };

}