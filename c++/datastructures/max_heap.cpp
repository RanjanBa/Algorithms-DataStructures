#define max_heap
#include <iostream>
#include <vector>

namespace maxheap
{
    template <typename T>
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

            swap(elements[index], elements[parentIndex]);
            bubbleUp(parentIndex);
        }

        void bubbleDown(int index)
        {
            if (index >= elements.size())
                return;

            int leftChildIndex = 2 * index + 1;
            if (leftChildIndex >= elements.size())
            {
                return;
            }

            int greaterElementIndex = -1;

            if (elements[index] < elements[leftChildIndex])
            {
                greaterElementIndex = leftChildIndex;
            }

            int rightChildIndex = 2 * index + 2;
            if (rightChildIndex < elements.size() && elements[leftChildIndex] < elements[rightChildIndex] && elements[index] < elements[rightChildIndex])
            {
                greaterElementIndex = rightChildIndex;
            }

            if (greaterElementIndex == -1)
                return;

            swap(elements[index], elements[greaterElementIndex]);
            bubbleDown(greaterElementIndex);
        }

    public:
        int size()
        {
            return elements.size();
        }

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