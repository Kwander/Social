template <class ItemType>
Node<ItemType>::Node() : next_{nullptr}
{
}

template <class ItemType>
Node<ItemType>::Node(const ItemType &item, Node<ItemType> *nextNode) : item_{item}, next_{nextNode} {}

template <class ItemType>
void Node<ItemType>::setItem(const ItemType &anItem)
{
    item_ = anItem;
}

template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextNodePtr)
{
    next_ = nextNodePtr;
}

template <class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item_;
}

template <class ItemType>
Node<ItemType> *Node<ItemType>::getNext() const
{
    return next_;
}
