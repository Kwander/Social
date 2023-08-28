#ifndef PROMOTIONAL_HPP_
#define PROMOTIONAL_HPP_

#include "Post.hpp"
#include <string>
#include <iostream>
#include <regex>

class Promotional : public Post
{
public:
    Promotional(const std::string &title, const std::string &body, const std::string &username, const std::string &url);
    std::string getLink() const;
    bool setLink(const std::string &link);
    void displayPost() override;

private:
    std::string url;
};

#endif // PROMOTIONAL_HPP_