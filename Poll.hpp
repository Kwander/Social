#ifndef POLL_HPP_
#define POLL_HPP_

#include "Post.hpp"
#include <vector>
#include <iostream>

class Poll : public Post
{
public:
    Poll(const std::string &name, const std::string &paragraph, const std::string &accountName, const std::vector<std::string> &pollOptions);
    bool votePoll(const int &index);
    void changePollOption(const std::string &option, const int &choiceNumber);
    void getPollOptions() const;
    int getPollVotes(const int &index) const;
    void displayPost() override;

private:
    std::vector<std::string> pollOptions;
    std::vector<int> numOfVotesForEachPoll;
};

#endif // POLL_HPP_