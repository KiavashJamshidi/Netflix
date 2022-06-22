#include "comment.h"
#include <iostream>
using namespace std;

Comment::Comment(int comment_id,string film_name,int film_id,string Message,int commenter){
    commentID = comment_id;
    filmName = film_name;
    filmID = film_id;
    messages.push_back(Message);
    Commenter = commenter;
}

void Comment::pushBackMessage(string str){
    messages.push_back(str);
}

bool Comment::is_availble() { return isAvailble == 1; }

int Comment::showCommentId() { return commentID; }

void Comment::setUnavailble() { isAvailble = 0; }

int Comment::showCommenter() {  return Commenter; }

int Comment::showFilmId() { return filmID; }

string Comment::showMessage(int i){ return messages[i]; }

int Comment::numOfMsgs(){ return messages.size(); }