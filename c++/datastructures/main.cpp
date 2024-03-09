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

int main()
{
    // creatLinkList();
    // createDoublyLinkList();
    // creatLRU();

    createAVLTree();

    return 0;
}