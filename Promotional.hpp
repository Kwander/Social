/*
Kevin Wander
Project 2
CS235, 9/22/2022
*/

#ifndef PROMOTIONAL_HPP_
#define PROMOTIONAL_HPP_
#include "Post.hpp" 


class Promotional : public Post
{
public:
    Promotional(const std::string title, const std::string body, const std::string username, const std::string url);
    std::string getLink() const; 
    bool setLink(const std::string link); 
    void displayPost() override;
private:
    std::string url;
};

#endif