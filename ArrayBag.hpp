#ifndef ARRAY_BAG_H
#define ARRAY_BAG_H

#include <vector>

template <class ItemType>
class ArrayBag
{
public:
   ArrayBag();
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType &new_entry);
   bool remove(const ItemType &an_entry);
   void clear();
   bool contains(const ItemType &an_entry) const;
   int getFrequencyOf(const ItemType &an_entry) const;

private:
   static const int DEFAULT_CAPACITY = 10;
   ItemType items_[DEFAULT_CAPACITY];
   int item_count_;

   int getIndexOf(const ItemType &target) const;
};

#include "ArrayBag.cpp"
#endif