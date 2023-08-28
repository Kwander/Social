#include "Network.hpp"

template <typename ItemType>
Network<ItemType>::Network() : account_count_(0), feed_({})
{
}

template <typename ItemType>
int Network<ItemType>::getSizeOfNetwork() const
{
    return account_count_;
}

template <typename ItemType>
bool Network<ItemType>::isEmpty() const
{
    return account_count_ == 0;
}

template <typename ItemType>
void Network<ItemType>::clear()
{
    while (account_count_ > 0)
    {
        removeAccount(*(network_[account_count_ - 1]));
    }
}

template <typename ItemType>
bool Network<ItemType>::containsAccount(const ItemType &an_entry) const
{
    return getIndexOf(an_entry.getUsername()) > -1;
}

template <typename ItemType>
bool Network<ItemType>::addAccount(ItemType *newEntry)
{
    bool hasRoom = (account_count_ < DEFAULT_CAPACITY);
    int existingIndex = getIndexOf(newEntry->getUsername());

    if (hasRoom && existingIndex < 0)
    {
        network_[account_count_] = newEntry;
        newEntry->setNetwork(this);
        account_count_++;
        return true;
    }

    return false;
}

template <typename ItemType>
bool Network<ItemType>::removeAccount(ItemType *anEntry)
{
    int foundIndex = getIndexOf(anEntry->getUsername());
    bool canRemove = !isEmpty() && (foundIndex > -1);

    if (canRemove)
    {
        account_count_--;

        if (account_count_ != foundIndex)
        {
            network_[foundIndex] = network_[account_count_];
        }
    }

    return canRemove;
}

template <typename ItemType>
void Network<ItemType>::printFeedForAccount(ItemType &an_entry)
{
    int location = getIndexOf(an_entry.getUsername());
    if (location > -1)
    {
        std::vector<std::string> following_list = network_[location]->viewFollowing();
        Node<Post *> *itt = feed_.getHeadPtr();
        while (itt != nullptr)
        {
            Post *curr_item = itt->getItem();
            std::string curr_user = curr_item->getUsername();
            for (std::string acc_username : following_list)
            {
                if (acc_username == curr_user)
                {
                    curr_item->displayPost();
                    break;
                }
            }
            itt = itt->getNext();
        }
    }
}

template <typename ItemType>
void Network<ItemType>::populateNetwork(const std::string &input)
{
    std::fstream fin;
    fin.open(input, std::ios::in);
    std::string usr = "";
    std::string pswd = "";
    std::string line;
    std::string word;
    while (std::getline(fin, line))
    {
        if (line == ";")
        {
            break;
        }
        std::stringstream s(line);
        s >> usr;
        s >> pswd;
        if (usr == "" || pswd == "")
        {
            std::cout << "Improper format" << std::endl;
            break;
        }
        ItemType *new_entry = new ItemType(usr, pswd);
        bool is_added = addAccount(*new_entry);
        if (!is_added)
        {
            std::cout << "Error when adding account" << std::endl;
            break;
        }
        usr = "";
        pswd = "";
    }
    fin.close();
}

template <typename ItemType>
int Network<ItemType>::getIndexOf(const std::string &username) const
{
    bool found = false;
    int result = -1;
    int index = 0;
    while (!found && (index < account_count_))
    {
        if (network_[index]->getUsername() == username)
        {
            found = true;
            result = index;
        }
        else
        {
            index++;
        }
    }
    return result;
}

template <typename ItemType>
bool Network<ItemType>::authenticateFollow(ItemType &anEntry, const std::string &username) const
{
    int indexUser = getIndexOf(anEntry.getUsername());

    if (indexUser > -1)
    {
        int index = getIndexOf(username);

        if (index > -1)
        {
            anEntry.followAccount(username);
            return true;
        }
    }

    return false;
}

template <typename ItemType>
bool Network<ItemType>::updateFeed(Post *post)
{
    return feed_.moveItemToTop(post);
}

template <typename ItemType>
void Network<ItemType>::addToFeed(Post *p)
{
    if (getIndexOf(p->getUsername()) > -1)
        feed_.insert(p, 0);
}

template <typename ItemType>
bool Network<ItemType>::removePostFromFeed(Post *post)
{
    int postPosition = feed_.getIndexOf(post);

    if (postPosition > -1)
    {
        feed_.remove(postPosition);
        return true;
    }
    return false;
}

template <typename ItemType>
void Network<ItemType>::printFeed()
{
    Node<Post *> *header = feed_.getHeadPtr();

    while (header != nullptr)
    {
        std::cout << header->getItem() << '\n';
        header = header->getNext();
    }
}

template <typename ItemType>
void Network<ItemType>::operator-=(Network<ItemType> &a_network)
{
    int index = 0;
    int this_index = 0;
    int accounts_left = a_network.account_count_;
    while (accounts_left > 0)
    {
        if (this->account_count_ == 0)
        {
            break;
        }
        this_index = this->getIndexOf(a_network.network_[index]->getUsername());
        if (this_index > -1)
        {
            this->removeAccount(*(this->network_[this_index]));
        }
        index++;
        accounts_left--;
    }
}

template <typename ItemType>
int Network<ItemType>::removeIfContains(const std::string &postBody)
{
    int occurrences{0};
    if (feed_.getSize() == 0)
    {
        return occurrences;
    }
    else
    {
        Node<Post *> *curr = feed_.getHeadPtr();
        while (curr != nullptr)
        {
            Post *curr_post = curr->getItem();
            curr = curr->getNext();
            if (curr_post->getTitle().find(postBody) != std::string::npos ||
                curr_post->getBody().find(postBody) != std::string::npos)
            {
                int acc_index = getIndexOf(curr_post->getUsername());
                if (acc_index > -1)
                {
                    network_[acc_index]->removePost(curr_post);
                }
                occurrences++;
            }
        }
    }
    return occurrences;
}

template <typename ItemType>
template <typename Comparator>
LinkedList<Post *> Network<ItemType>::bSortByUsername(Comparator Diff, int *SwapCounter)
{
    LinkedList<Post *> result = feed_;
    result.bubbleSort(Diff, SwapCounter);
    return result;
}
