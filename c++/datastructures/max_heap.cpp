#define max_heap
#include <iostream>
#include <vector>

namespace maxheap
{
    template<typename T>
    class MaxHeap
    {
    private:
        std::vector<T> elements;

        void swap(T &a, T &b)
        {
            T t = a;
            a = b;
            b = t;
        }

        void bubbleUp(int index)
        {
            if (index == 0)
                return;

            int parentIndex = (index - 1) / 2;

            if (elements[parentIndex] >= elements[index])
                return;

            // int leftChildIndex = 2 * parentIndex + 1;
            // int rightChildIndex = 2 * parentIndex + 2;
            // int smallElementIndex = leftChildIndex;
            // if (elements[leftChildIndex] > elements[rightChildIndex])
            // {
            //     smallElementIndex = rightChildIndex;
            // }

            swap(elements[index], elements[parentIndex]);
            bubbleUp(parentIndex);
        }

        void bubbleDown(int index)
        {
            if (index >= elements.size())
                return;

            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;

            int greaterElementIndex = leftChildIndex;
            if (elements[leftChildIndex] < elements[rightChildIndex])
            {
                greaterElementIndex = rightChildIndex;
            }

            swap(elements[index], elements[greaterElementIndex]);
            bubbleDown(greaterElementIndex);
        }

    public:
        void insert(T ele)
        {
            if (elements.size() == 0)
            {
                elements.push_back(ele);
                return;
            }

            elements.push_back(ele);
            bubbleUp(elements.size() - 1);
        }

        int top()
        {
            if (elements.size() == 0)
            {
                throw 0;
            }

            return elements[0];
        }

        void pop()
        {
            elements[0] = elements[elements.size() - 1];
            elements.pop_back();
            bubbleDown(0);
        }

        void print()
        {
            for (T a : elements)
            {
                std::cout << a << " ";
            }
            cout << "\n";
        }
    };
}