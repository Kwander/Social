#include "Post.hpp"

Post::Post(std::string title, std::string body, std::string username)
    : post_title_(std::move(title)),
      post_body_(std::move(body)),
      time_stamp_(time(nullptr)),
      username_(std::move(username))
{
}

std::string Post::getTitle() const
{
    return post_title_;
}

void Post::setTitle(const std::string &title)
{
    post_title_ = title;
}

std::string Post::getBody() const
{
    return post_body_;
}

void Post::setBody(const std::string &body)
{
    post_body_ = body;
}

std::string Post::getUsername() const
{
    return username_;
}

void Post::setUsername(const std::string &username)
{
    username_ = username;
}

void Post::getTimeStamp() const
{
    std::cout << "Posted on: " << asctime(localtime(&time_stamp_));
}

void Post::updateTimeStamp()
{
    time_stamp_ = time(nullptr);
}

bool Post::operator<(const Post &other) const
{
    return getUsername() < other.getUsername();
}

bool Post::operator>(const Post &other) const
{
    return getUsername() > other.getUsername();
}
