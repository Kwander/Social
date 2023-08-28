#ifndef NODE_HPP_
#define NODE_HPP_

template <typename ItemType>
class Node
{
public:
    Node();
    Node(const ItemType &item, Node<ItemType> *nextNode = nullptr);

    void setItem(const ItemType &anItem);
    void setNext(Node<ItemType> *nextNodePtr);

    ItemType getItem() const;
    Node<ItemType> *getNext() const;

private:
    ItemType item_;
    Node<ItemType> *next_;
};

#include "Node.cpp"
#endif // NODE_HPP_