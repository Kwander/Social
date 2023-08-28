#include <iostream>
#include <string>
#include <cstdlib>

template <typename ItemType>
LinkedList<ItemType>::LinkedList()
{
    head_ = nullptr;
    size_ = 0;
}

template <typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType> &list) 
{
    head_ = nullptr;
    size_ = 0;
    if (!list.isEmpty())
    {
        Node<ItemType> *copyHead = list.getHeadPtr();
        int counter = 0;

        while (counter < list.getSize())
        {
            insert(copyHead->getItem(), counter);
            counter++;
            copyHead = copyHead->getNext();
        }
    }
}

template <typename ItemType>
Node<ItemType> *LinkedList<ItemType>::getHeadPtr() const
{
    return head_;
}

template <typename ItemType>
void LinkedList<ItemType>::clear()
{
    Node<ItemType> *curr_item = head_;
    Node<ItemType> *temp = curr_item;
    for (int i = 0; i < size_; i++)
    {
        temp = curr_item;
        curr_item = curr_item->getNext();
        delete temp;
    }
    temp = nullptr;
    size_ = 0;
}

template <typename ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}

template <typename ItemType>
bool LinkedList<ItemType>::insert(const ItemType &item, const int &position)
{
    if ((position < 0 || position > size_))
    {
        return false;
    }

    Node<ItemType> *node = new Node<ItemType>();
    node->setItem(item);

    if (size_ == 0)
    {
        head_ = node;
    }
    else
    {
        Node<ItemType> *iterator;

        if (position == 0)
        {
            node->setNext(head_);
            head_ = node;
        }

        else if (position == size_)
        {
            iterator = getAtPos(size_ - 1);
            iterator->setNext(node);
        }
        else
        {
            iterator = getAtPos(position - 1);
            node->setNext(iterator->getNext());
            iterator->setNext(node);
        }
    }
    size_++;
    return true;
}

template <typename ItemType>
bool LinkedList<ItemType>::remove(const int &position)
{
    if (position < 0 || position >= size_)
    {
        return false;
    }

    Node<ItemType> *iterator = nullptr;
    Node<ItemType> *previous = nullptr;

    if (position == 0)
    {
        iterator = head_;
        head_ = head_->getNext();
    }
    else
    {
        previous = getAtPos(position - 1);
        iterator = getAtPos(position);
        previous->setNext(iterator->getNext());
    }

    size_--;
    previous = nullptr;
    iterator->setNext(nullptr);
    delete iterator;
    return true;
}

template <typename ItemType>
void LinkedList<ItemType>::reverseCopy(const LinkedList<ItemType> &a_list)
{
    LinkedList<ItemType> newList(a_list);

    Node<ItemType> *current = newList.getHeadPtr();
    const int START = 0;
    const int END = newList.getSize();

    while (current != nullptr)
    {
        insert(current->getItem(), START);
        current = current->getNext();
        remove(END);
    }
}

template <typename ItemType>
int LinkedList<ItemType>::getSize() const
{
    return size_;
}

template <typename ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return size_ == 0 ? true : false;
}

template <typename ItemType>
bool LinkedList<ItemType>::moveItem(int &current_position, const int &new_position)
{
    if (
        (current_position > -1 && current_position < size_) &&
        (new_position > -1 && new_position < size_))
    {
        if (new_position != current_position)
        {
            if (new_position < current_position)
            {
                Node<ItemType> *temp_curr = this->getAtPos(current_position);
                Node<ItemType> *temp_prev = this->getAtPos(current_position - 1);
                temp_curr = temp_prev;
                temp_prev = temp_curr;
                current_position--;
            }
            else
            {
                Node<ItemType> *temp_curr = this->getAtPos(current_position);
                Node<ItemType> *temp_next = this->getAtPos(current_position + 1);
                temp_curr = temp_next;
                temp_next = temp_curr;
                current_position++;
            }

            return moveItem(current_position, new_position);
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

template <typename ItemType>
bool LinkedList<ItemType>::moveItemToTop(const ItemType &item)
{
    if (getIndexOf(item) < 1) 
        return false;
    else
    {
        Node<ItemType> *new_head = new Node<ItemType>(); 
        new_head->setItem(item);                         
        remove(getIndexOf(item));                        
        new_head->setNext(head_);                        
        head_ = new_head;                                
        return true;
    }
}

template <typename ItemType>
Node<ItemType> *LinkedList<ItemType>::getAtPos(const int &pos) const
{

    if (pos < 0 || pos >= size_)
    {
        return nullptr;
    }

    Node<ItemType> *curr_item = head_;
    int counter = 0;
    while (counter < pos && curr_item != nullptr)
    {
        counter++;
        curr_item = curr_item->getNext();
    }
    return curr_item;
}

template <typename ItemType>
int LinkedList<ItemType>::getIndexOf(const ItemType &item) const
{
    Node<ItemType> *curr_item = head_;
    int counter = 0;
    while (curr_item != nullptr)
    {
        if (curr_item->getItem() == item)
        {
            return counter;
        }
        counter++;
        curr_item = curr_item->getNext();
    }
    return -1;
}


template <typename ItemType>
template <typename Comparator>
void LinkedList<ItemType>::bubbleSort(Comparator Diff, int *SwapCounter)
{
    Node<ItemType> *Curr = head_;

    for (int i = 0; i < size_; i++)
    {
        Curr = head_;
        while (Curr->getNext() != nullptr)
        {
            if (!Diff(*(Curr->getItem()), *(Curr->getNext()->getItem())))
            {
                ItemType temp = Curr->getItem();
                Curr->setItem(Curr->getNext()->getItem());
                Curr->getNext()->setItem(temp);
                (*SwapCounter)++;
            }
            Curr = Curr->getNext();
        }
    }
}