#ifndef COMMENT_H
#define COMMENT_H
#include <string>
#include <vector>

class Comment{
public:
    Comment(int comment_id,std::string film_name,int film_id,std::string Message,int Whichcommenter);
    void pushBackMessage(std::string str);
    bool is_availble();
    void setUnavailble();
    int showCommentId();
    int showCommenter();
    int showFilmId();
    std::string showMessage(int i);
    int numOfMsgs();
private:
    int commentID;
    std::string filmName;
    int filmID;
    int Commenter;
    int isAvailble = 1;
    std::vector<std::string> messages;
};

#endif