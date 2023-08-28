#ifndef POST_
#define POST_

#include <iostream>
#include <string>
#include <ctime>

class Post
{
public:
   Post(std::string title, std::string body, std::string username);

   std::string getTitle() const;
   void setTitle(const std::string &title);

   std::string getBody() const;
   void setBody(const std::string &body);

   std::string getUsername() const;
   void setUsername(const std::string &username);

   void getTimeStamp() const;
   void updateTimeStamp();

   virtual void displayPost() = 0;

   bool operator<(const Post &other) const;
   bool operator>(const Post &other) const;

private:
   std::string post_title_;
   std::string post_body_;
   time_t time_stamp_;
   std::string username_;
};

#endif // POST_
