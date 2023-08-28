#ifndef LinkedList_
#define LinkedList_

#include <iostream>
#include "Node.hpp"

template <typename ItemType>
class LinkedList
{
public:
    LinkedList();

    LinkedList(const LinkedList<ItemType> &list);

    ~LinkedList();

    bool insert(const ItemType &item, const int &position);

    bool remove(const int &position);

    int getSize() const;

    Node<ItemType> *getHeadPtr() const;

    bool isEmpty() const;

    void clear();

    int getIndexOf(const ItemType &item) const;

    bool moveItem(int &current_position, const int &new_position);

    bool moveItemToTop(const ItemType &item);

    void reverseCopy(const LinkedList<ItemType> &a_list);

    template <class Comparator>
    void bubbleSort(const Comparator Diff, int *SwapCounter);

private:
    Node<ItemType> *getAtPos(const int &pos) const;
    Node<ItemType> *head_;
    size_t size_;
};

#include "LinkedList.cpp"
#endif
