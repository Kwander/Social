#include "Poll.hpp"

Poll::Poll(const std::string &name, const std::string &paragraph, const std::string &accountName, const std::vector<std::string> &options)
    : Post(name, paragraph, accountName)
{
    for (const auto &option : options)
    {
        pollOptions.push_back(option);
        numOfVotesForEachPoll.push_back(0);
    }
}

bool Poll::votePoll(const int &index)
{
    if (index >= 0 && index < pollOptions.size())
    {
        numOfVotesForEachPoll[index]++;
        return true;
    }
    return false;
}

void Poll::changePollOption(const std::string &option, const int &choiceNumber)
{
    if (choiceNumber >= pollOptions.size())
    {
        pollOptions.push_back(option);
        numOfVotesForEachPoll.push_back(0);
    }
    else if (choiceNumber >= 0 && choiceNumber < pollOptions.size())
    {
        pollOptions[choiceNumber] = option;
        numOfVotesForEachPoll[choiceNumber] = 0;
    }
}

void Poll::getPollOptions() const
{
    for (size_t i = 0; i < pollOptions.size(); i++)
    {
        std::cout << numOfVotesForEachPoll[i] << " votes for: " << pollOptions[i] << std::endl;
    }
}

int Poll::getPollVotes(const int &index) const
{
    if (index >= 0 && index < pollOptions.size())
    {
        return numOfVotesForEachPoll[index];
    }
    return 0;
}

void Poll::displayPost()
{
    std::cout << std::endl
              << getTitle() << " at ";
    getTimeStamp();
    std::cout << getBody() << "\n";
    getPollOptions();
    std::cout << std::endl;
}
