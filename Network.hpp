#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <fstream>
#include <vector>
#include <string>
#include "Post.hpp"
#include "LinkedList.hpp"
#include "Account.hpp"

template <typename ItemType>
class Network
{
public:
   Network();

   int getSizeOfNetwork() const;
   bool isEmpty() const;

   bool addAccount(ItemType *newEntry);
   bool removeAccount(ItemType *anEntry);
   void clear();
   bool containsAccount(const ItemType &anEntry) const;

   void populateNetwork(const std::string &input);

   void printFeedForAccount(ItemType &anEntry);
   bool authenticateFollow(ItemType &anEntry, const std::string &username) const;

   void addToFeed(Post *p);
   bool removePostFromFeed(Post *post);
   bool updateFeed(Post *post);

   void printFeed();

   void operator-=(Network<ItemType> &aNetwork);
   int removeIfContains(const std::string &postBody);

   template <typename Comparator>
   LinkedList<Post *> bSortByUsername(Comparator Diff, int *SwapCounter);

protected:
   static const int DEFAULT_CAPACITY = 200;
   ItemType *network_[DEFAULT_CAPACITY];
   int account_count_;
   LinkedList<Post *> feed_;

   int getIndexOf(const std::string &username) const;
};

#include "Network.cpp"
#endif // NETWORK_HPP_