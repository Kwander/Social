#include "Account.hpp"

Account::Account() : username_(""), password_(""), posts_(), following_(), net_(nullptr)
{
}

Account::Account(std::string username, std::string password)
    : username_(username), password_(password), posts_(), following_(), net_(nullptr) {}

std::string Account::getUsername() const { return username_; }
void Account::setUsername(const std::string &username) { username_ = username; }

std::string Account::getPassword() const { return password_; }
void Account::setPassword(const std::string &password) { password_ = password; }

Network<Account> *Account::getNetwork() const { return net_; }
void Account::setNetwork(Network<Account> *network) { net_ = network; }

bool Account::addPost(Post *newPost)
{
    posts_.insert(newPost, 0);
    if (net_ != nullptr)
    {
        net_->addToFeed(newPost);
        return true;
    }
    return false;
}

void Account::viewPosts() const
{
    Node<Post *> *itt = posts_.getHeadPtr();
    while (itt != nullptr)
    {
        itt->getItem()->displayPost();
        itt = itt->getNext();
    }
}

bool Account::followAccount(const std::string username)
{
    if (!net_ || std::find(following_.begin(), following_.end(), username) != following_.end())
    {
        return false;
    }
    following_.push_back(username);
    return true;
}

std::vector<std::string> Account::viewFollowing() const { return following_; }

bool Account::operator==(const Account &acc) const
{
    return (acc.getUsername() == username_ && acc.getPassword() == password_);
}

bool Account::removePost(Post *post)
{
    int postPosition = posts_.getIndexOf(post);
    if (postPosition > -1)
    {
        posts_.remove(postPosition);
        if (net_ != nullptr)
        {
            net_->removePostFromFeed(post);
        }
        return true;
    }
    return false;
}

bool Account::updatePost(Post *post, std::string new_title, std::string new_body)
{
    if (!post)
    {
        return false;
    }

    if (!new_title.empty())
    {
        post->setTitle(new_title);
    }

    if (!new_body.empty())
    {
        post->setBody(new_body);
    }

    post->updateTimeStamp();

    if (net_)
    {
        return net_->updateFeed(post);
    }
    return false;
}