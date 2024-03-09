#include <unordered_map>
#include <stdexcept>

#define lru_cache

#ifndef dbly_link_list
#include "doubly_linklist.cpp"
#endif

template <typename T, typename U>
class LRUCache
{
private:
    int capacity;
    dblylinklist::DoublyLinkList<T> dblist;
    unordered_map<T, U> un_map;

public:
    LRUCache(int capacity = 5) : capacity(capacity) {}

    bool isContain(T key)
    {
        return un_map.find(key) != un_map.end();
    }

    U get(T key)
    {
        if (un_map.find(key) == un_map.end())
        {
            throw runtime_error("No key found");
        }

        dblist.erase(key);
        dblist.pushFront(key);

        return un_map[key];
    }

    void put(T key, U value)
    {
        if (un_map.find(key) != un_map.end())
        {
            dblist.erase(key);
        }
        else
        {
            un_map[key] = value;
        }

        dblist.pushFront(key);

        if (un_map.size() > capacity)
        {
            T k = dblist.popBack();
            un_map.erase(k);
        }
    }

    void showUpdatedListKey()
    {
        dblist.printList();
    }

    ~LRUCache() {}
};
