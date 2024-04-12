#define dynamic_array

namespace dynamicarray
{
    template <typename T>
    class DynamicArray
    {
    private:
        const int default_capacity;
        int capacity;
        int count;
        T *array;

        void rightShiftElements()
        {
            for (int i = count - 1; i >= 0; i--)
            {
                array[i + 1] = array[i];
            }
        }

        void leftShiftElements()
        {
            for (int i = 1; i < count; i++)
            {
                array[i - 1] = array[i];
            }
        }

        void copyArray(int new_capacity)
        {
            if (new_capacity < default_capacity)
                return;

            capacity = new_capacity;
            T *new_array = (T *)malloc(capacity * sizeof(T));

            for (int i = 0; i < count; i++)
            {
                new_array[i] = array[i];
            }
            array = new_array;
        }

    public:
        DynamicArray(int capacity = 10) : capacity(capacity), count(0), default_capacity(capacity)
        {
            array = (T *)malloc(capacity * sizeof(T));
        }

        void pushBack(T value)
        {
            if (count == capacity)
            {
                copyArray(2 * capacity);
            }

            array[count] = value;
            count++;
        }

        void pushFront(T value)
        {
            if (count == capacity)
            {
                copyArray(2 * capacity);
            }

            rightShiftElements();
            array[0] = value;
            count++;
        }

        T popBack()
        {
            if (count < capacity / 2)
            {
                copyArray(capacity / 2);
            }
            return array[--count];
        }

        T popFront()
        {
            T val = array[0];
            if (count < capacity / 2)
            {
                copyArray(capacity / 2);
            }

            leftShiftElements();

            count--;
            return val;
        }

        int size() { return count; }

        void printArray()
        {
            if (count == 0)
                return;

            cout << "capacity : " << capacity << ", size : " << count << endl;
            for (int i = 0; i < count; i++)
            {
                cout << array[i] << " ";
            }
            cout << endl;
        }

        ~DynamicArray() {}
    };

}