#include "Promotional.hpp"

Promotional::Promotional(const std::string &title, const std::string &body, const std::string &username, const std::string &url)
    : Post(title, body, username)
{
  const std::string httpPrefix = "http://www.";
  const std::string httpsPrefix = "https://www.";

  if (url.compare(0, httpsPrefix.size(), httpsPrefix) == 0 || url.compare(0, httpPrefix.size(), httpPrefix) == 0)
  {
    this->url = url;
  }
  else
  {
    this->url = "Broken Link";
  }
}

std::string Promotional::getLink() const
{
  return this->url;
}

bool Promotional::setLink(const std::string &link)
{
  const std::regex linkPattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");

  if (std::regex_match(link, linkPattern))
  {
    url = link;
    return true;
  }
  else
  {
    url = "Broken Link";
    return false;
  }
}

void Promotional::displayPost()
{
  std::cout << std::endl
            << getTitle() << " at ";
  getTimeStamp();
  std::cout << getBody() << "\n\n"
            << getLink() << std::endl;
}
