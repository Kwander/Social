#include "ArrayBag.hpp"

template <class ItemType>
ArrayBag<ItemType>::ArrayBag() : item_count_(0)
{
}

template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
   return item_count_;
}

template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
   return item_count_ == 0;
}

template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType &new_entry)
{
   if (item_count_ < DEFAULT_CAPACITY)
   {
      items_[item_count_] = new_entry;
      item_count_++;
      return true;
   }
   return false;
}

template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &an_entry)
{
   int found_index = getIndexOf(an_entry);
   if (!isEmpty() && (found_index > -1))
   {
      item_count_--;
      items_[found_index] = items_[item_count_];
      return true;
   }
   return false;
}

template <class ItemType>
void ArrayBag<ItemType>::clear()
{
   item_count_ = 0;
}

template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &an_entry) const
{
   int frequency = 0;
   for (int i = 0; i < item_count_; ++i)
   {
      if (items_[i] == an_entry)
      {
         frequency++;
      }
   }
   return frequency;
}

template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &an_entry) const
{
   return getIndexOf(an_entry) > -1;
}

template <class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &target) const
{
   for (int i = 0; i < item_count_; ++i)
   {
      if (items_[i] == target)
      {
         return i;
      }
   }
   return -1;
}
