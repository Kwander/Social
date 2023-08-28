#include "General.hpp"

General::General(std::string name, std::string description, std::string username)
    : Post(std::move(name), std::move(description), std::move(username))
{
}

bool General::reactToPost(const Reactions &reaction)
{
    if (reaction >= Reactions::LIKE && reaction <= Reactions::ANGRY)
    {
        reactions_[static_cast<int>(reaction)] += 1;
        return true;
    }
    return false;
}

void General::getReactions() const
{
    const std::vector<std::string> reactionNames = {
        "Likes", "Dislike", "Laugh", "Wow", "Sad", "Angry"};
    for (int i = 0; i < 6; ++i)
    {
        std::cout << reactionNames[i] << " : " << reactions_[i] << " | ";
    }
    std::cout << std::endl;
}

void General::displayPost()
{
    std::cout << "\n"
              << getTitle() << " at ";
    getTimeStamp();
    std::cout << getBody() << std::endl;
    getReactions();
}
