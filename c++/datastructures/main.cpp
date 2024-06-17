#include <iostream>
using namespace std;

#ifndef link_list
#include "linklist.cpp"
#endif

#ifndef dbly_link_list
#include "doubly_linklist.cpp"
#endif

#ifndef lru_cache
#include "lru_cache.cpp"
#endif

#ifndef red_black_tree
#include "red_black_tree.cpp"
#endif

#ifndef avl_tree
#include "avl_tree.cpp"
#endif

#ifndef dynamic_array
#include "dynamic_array.cpp"
#endif

#ifndef max_heap
#include "max_heap.cpp"
#endif

void creatLinkList()
{
    linklist::LinkList<int> list;

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushFront(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushFront(100);

    list.printList();

    list.popBack();
    list.popFront();

    list.printList();

    list.pushBack(9);
    list.pushFront(15);
    list.printList();

    list.erase(1);
    list.erase(1);
    list.erase(200);
    list.erase(15);
    list.erase(9);
    list.pushFront(55);
    list.pushBack(75);
    list.printList();
}

void createDoublyLinkList()
{
    dblylinklist::DoublyLinkList<int> list;

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushFront(0);
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushFront(100);

    list.printList();
    list.printListReverse();

    list.popBack();
    list.popFront();

    list.printList();
    list.printListReverse();

    list.pushBack(9);
    list.pushFront(15);

    list.erase(1);
    list.erase(3);
    list.erase(3);

    list.printList();
    list.printListReverse();
}

void creatLRU()
{
    LRUCache<int, int> cache(3);
    cache.put(1, 2);
    cache.put(2, 5);
    cache.put(3, 6);
    cache.showUpdatedListKey();
    cout << cache.get(2) << endl;
    cache.showUpdatedListKey();

    cache.put(5, 6);
    cache.put(6, 100);
    cache.showUpdatedListKey();

    if (cache.isContain(1))
    {
        cout << cache.get(1) << endl;
    }
    cache.showUpdatedListKey();
    cache.get(2);
    cache.showUpdatedListKey();
}

void createAVLTree()
{
    cout << "AVL TREE" << endl;
    avltree::AVLTree<int> avl;

    cout << "Stage 1" << endl;
    // avl.insert(1);
    // avl.insert(2);
    // avl.preOrder();

    // cout << "Stage 2" << endl;
    // avl.insert(3);
    // avl.insert(4);
    // avl.insert(5);
    // avl.insert(-1);
    // avl.insert(-2);

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    avl.preOrder();

    cout << "InOrder : " << endl;
    avl.inOrder();
}

void createDynamicArray()
{
    dynamicarray::DynamicArray<int> dyarr(5);

    dyarr.pushBack(12);
    dyarr.pushBack(17);
    dyarr.pushBack(15);
    dyarr.pushBack(13);

    dyarr.printArray();

    dyarr.pushBack(26);
    dyarr.pushBack(35);
    dyarr.pushBack(47);
    dyarr.printArray();

    dyarr.pushBack(21);
    dyarr.pushBack(26);
    dyarr.pushBack(19);
    dyarr.pushBack(89);
    dyarr.pushBack(93);
    dyarr.printArray();

    dyarr.popBack();
    dyarr.popBack();
    dyarr.popBack();
    dyarr.popBack();
    dyarr.printArray();

    dyarr.pushFront(55);
    dyarr.pushFront(68);
    dyarr.printArray();

    dyarr.pushBack(34);
    dyarr.printArray();
    dyarr.popBack();
    dyarr.popFront();
    dyarr.popFront();
    dyarr.printArray();

    dyarr.popFront();
    dyarr.popFront();
    dyarr.popFront();
    dyarr.popFront();
    dyarr.printArray();
}

int main()
{
    // creatLinkList();
    // createDoublyLinkList();
    // creatLRU();

    // createAVLTree();

    // createDynamicArray();

    maxheap::MaxHeap<int> heap;

    heap.insert(60);
    heap.insert(50);
    heap.insert(45);
    heap.insert(30);
    heap.insert(40);
    heap.insert(30);

    heap.print();

    heap.insert(70);
    heap.print();

    heap.pop();
    heap.print();

    maxheap::MaxHeap<char> heap2;

    heap2.insert('c');
    heap2.insert('b');

    heap2.print();

    heap2.insert('a');
    heap2.print();

    heap2.pop();
    heap2.print();

    return 0;
}