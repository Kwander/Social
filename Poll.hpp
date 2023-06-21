/*
Kevin Wander
Project 2
CS235, 9/18/2022
*/

#ifndef POLL_HPP_
#define POLL_HPP_
#include "Post.hpp"
#include <vector>

class Poll : public Post{
public:
    Poll(const std::string Name, const std::string Paragraph, const std::string AccountName, const std::vector<std::string> pollGrOptions);
    bool votePoll(const int& indx); //WORKS
    void changePollOption(const std::string& option, const int& choice_number); //WORKS
    void getPollOptions() const; //WORKS
    int getPollVotes(const int& indx) const; //Works
    void displayPost() override; // works

private:
    std::vector<std::string> pollOptions;   // Do you like cats
    std::vector<int> numOfVotesForEachPoll; // the number of votes for
    // the poll option in the first position , the second integer indicates the number of votes
    // for the second poll option, etc.
};

#endif