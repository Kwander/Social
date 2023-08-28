#ifndef GENERAL_
#define GENERAL_

#include "Post.hpp"
#include <string>
#include <iostream>
#include <vector>

enum class Reactions
{
    LIKE,
    DISLIKE,
    LAUGH,
    WOW,
    SAD,
    ANGRY
};

class General : public Post
{
public:
    General(std::string name, std::string description, std::string username);

    bool reactToPost(const Reactions &reaction);

    void getReactions() const;

    virtual void displayPost() override;

private:
    int reactions_[6] = {0};
};

#endif 