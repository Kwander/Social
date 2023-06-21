/*
Kevin Wander
Project 2
CS235, 9/18/2022
*/

#include "Poll.hpp"
#include <iostream>

/**
     Parameterized constructor.
    @param    : The title (name) of the Poll post (a string)
    @param    : The question (body) of the Poll post (a string)
    @param    : : The username of the Account that added this poll (a string)
    @param    : A vector of options for the Poll post

    @post     :Sets the title, body and username of the Poll post to the value of the parameters.
                It will also generate the current time and store it and will initialize
                the vectors of options and their respective number of votes.
*/
Poll::Poll(const std::string title, const std::string body, const std::string username, const std::vector<std::string> optionsVec) : Post(title, body, username){
    for (size_t i = 0; i < optionsVec.size(); i++){
        pollOptions.push_back(optionsVec[i]);
        numOfVotesForEachPoll.push_back(0);
    }
}


/**
    @param     : a reference to int between 0 < number of options
    @return    : True if index is within range and we can vote for a poll,
                false otherwise
    @post      : Increments the poll votes based on the index which
                will refer to the index in the poll options
*/
bool Poll::votePoll(const int &indx)
{
    if ((indx < 0) || (indx >= pollOptions.size()))
    {
        return false;
    }
    else
    {
        numOfVotesForEachPoll[indx]++;
        return true;
    }
}

/**
     Mutator function used to either add a poll or change one of the poll options
        @param     : A reference to the new poll option
        @param     : A reference to int that can either represent the index of the
                    existing option that will be replaced
                    or if choice_number > current number of options,
                    it will add this new option to the poll.

    @post       : Resets the number of votes for this option.
*/
void Poll::changePollOption(const std::string &option, const int &choice_number)
{
    if (choice_number >= pollOptions.size()){
        pollOptions.push_back(option);
        numOfVotesForEachPoll.push_back(0);
    }
    else {
        pollOptions[choice_number] = option;
        numOfVotesForEachPoll[choice_number] = 0;
    }
}


/**
     Accessor function
    @post       : prints the reaction to the post in this format
                (example where option_n is the string at position n in the poll options vector):
                0 votes for: option_1
                5 votes for: option_2
                2 votes for: option_3
                ...
*/
void Poll::getPollOptions() const
{
    for (int i = 0; i < pollOptions.size(); i++)
        std::cout << numOfVotesForEachPoll[i] << " votes for: " << pollOptions[i] << std::endl;
}





/**
     Accessor function
    @param      : The index of the option
    @return     : returns the number of votes for a given option
*/
int Poll::getPollVotes(const int &indx) const{
    if ((indx >= 0) && (indx < pollOptions.size()))
        return numOfVotesForEachPoll[indx];
}




/**
      @post   : displays the whole Poll post (example):
                \n
                {post_title_} at {time_stamp_}:
                {post_body_}
                \n
                0 votes for: option_1
                5 votes for: option_2
                2 votes for: option_3
                ...
                \n
   */
void Poll::displayPost()
{
    std::cout << std::endl << getTitle() << " at ";
    getTimeStamp();
    std::cout << getBody() << "\n";
    getPollOptions();
    std::cout << std::endl;
}
