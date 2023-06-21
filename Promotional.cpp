/*
Kevin Wander
Project 2
CS235, 9/22/2022
*/

#include "Promotional.hpp"
#include <regex>
#include <string.h>
#include <iostream>

/**
     Parameterized constructor.
        @param       : The name of the Promotional post (a string)
        @param       : The body of the Promotional post (a string)
        @param    : : The username of the Account that added this post (a string)
        @param       : The link of the Promotional post (a string)

    @post         : Sets the title, body, username and link (if it's a proper link otherwise "Broken Link")
                    of the Promotional to the value
                    of the parameters.
                    It will also generate the current time and store it.
*/
Promotional::Promotional(const std::string title, const std::string body, const std::string username, const std::string url) : Post(title, body, username){
    std::string beginning = url.substr(0, 12);
    std::string beginning2 = url.substr(0, 11);
    if ((beginning2 == "http://www.") || (beginning == "https://www."))
        this->url = url;
    else this->url = "Broken Link";
}




/**
      Accessor function
      @return  url: Returns the post link
   */
std::string Promotional::getLink() const
{
  return this->url;
}

/**
     @param    : A reference to the link that is in the format 'https://www.something.something'
                or 'http://www.something.something' with the last 'something' being at least 2 characters
    @return   : true if the link is correctly formatted, false otherwise

    @post     : If the link is not correctly formatted, store "Broken Link"
                in the link member variable, otherwise store the value of the
                parameter (Hint: see <regex>)
*/
bool Promotional::setLink(const std::string link){
  const std::regex Checker("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
  if (std::regex_match(link, Checker) == false){
    url = "Broken Link";
    return false;
  }else {
    url = link;
    return true;
  }
}

/**
      @post      : displays the entire Promotional post (example):
                  \n
                  {post_title_} at {time_stamp_}:
                  {post_body_}
                  \n
                  {link}
                  \n
*/
void Promotional::displayPost()
{
  std::cout << std::endl
            << getTitle() << " at ";
  getTimeStamp();
  std::cout << getBody() << "\n\n"
            << getLink() << std::endl;
}
