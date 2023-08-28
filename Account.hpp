#ifndef ACCOUNT_
#define ACCOUNT_

#include <iostream>
#include <string>
#include <vector>
#include "Post.hpp"
#include "Network.hpp"
#include "LinkedList.hpp"
#include "Node.hpp"

class Account
{
public:
  Account();
  Account(std::string username, std::string password);

  std::string getUsername() const;
  void setUsername(const std::string &username);

  std::string getPassword() const;
  void setPassword(const std::string &password);

  Network<Account> *getNetwork() const;
  void setNetwork(Network<Account> *network);

  bool addPost(Post *newPost);
  void viewPosts() const;

  bool followAccount(const std::string username);
  std::vector<std::string> viewFollowing() const;

  bool operator==(const Account &acc) const;

  bool removePost(Post *post);
  bool updatePost(Post *post, std::string new_title, std::string new_body);

private:
  std::string username_;
  std::string password_;
  LinkedList<Post *> posts_;
  std::vector<std::string> following_;
  Network<Account> *net_;
};

#endif // ACCOUNT_