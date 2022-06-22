#include "film.h"
#include <numeric>
#include <iostream>
using namespace std;

Film::Film(string _publisher, string _movieName,string _summary, string _director,int _year, int _length, int _price,int _idd, int publihserID){
    PublisherName = _publisher;
    MovieName = _movieName;
    director = _director;
    year = _year;
    length = _length;
    price = _price;
    summary = _summary;
    filmID = _idd;
    PublisherID = publihserID;
}

void Film::changeName(string _name){
    MovieName = _name;
}
void Film::changeYear(int _year){
    year = _year;
}
void Film::changeLength(int _length){
    length = _length;
}
void Film::changeSummary(string _summary){
    summary = _summary;
}
void Film::changeDirector(string _director){
    director = _director;
}

int Film::numOfMsgsOfThisCm(int j){
    return comments[j]->numOfMsgs();
}

void Film::addBuyersNum(){ numOfBuyers++; }

int Film::showPublisherId(){ return PublisherID; }

string Film::showCM(int cm, int msg){
    return comments[cm]->showMessage(msg);
}
void Film::gotDeleted(){is_Availble = 0;}

bool Film::IsAvailble(){return is_Availble == 1; }

string Film::showName(){return MovieName; }

string Film::showPublisherName() { return PublisherName; }

int Film::ShowFilmId(){return filmID;}

int Film::showPrice(){ return price; }
string Film::showDirector() { return director;}
string Film::showSummary(){return summary; }
int Film::showYear() { return year; }
int Film::showLength(){return length; }
float Film::showRate(){ return rate; }

int Film::whichCommentsHasThisId(int cmID){
    for (int i=0;i<comments.size();i++)
        if (comments[i]->showCommentId() == cmID)
            return i;
}

void Film::pushBackReplyMessage(int i,string str){
    comments[i]->pushBackMessage(str);
}
int Film::showIsAvailble(){return is_Availble; }
void Film::newComment(int comment_id,std::string film_name,int film_id,std::string Message,int commenter){
    comments.push_back(new Comment(comment_id,film_name,film_id,Message,commenter));
}

int Film::num_of_comments(){return comments.size(); }

bool Film::thisCmIsAvailble(int comment_id){
    for (int i=0;i<comments.size();i++)
        if (comments[i]->showCommentId() == comment_id){
            if (comments[i]->is_availble())
                return true;
        }
}

void Film::setThisCommentIDUnavailble(int comment_id){
    for (int i=0;i<comments.size();i++)
        if (comments[i]->showCommentId() == comment_id)
            comments[i]->setUnavailble();
}

int Film::showCommentId(int i){
    comments[i]->showCommentId();
}

void Film::addRate(int _rate, int userID){
    Rates[userID] = _rate;
    sumOfRates =  accumulate(begin(Rates), end(Rates), 0, [] (float value, const std::map<int, float>::value_type& p)
        { return value + p.second; });
    rate = (sumOfRates) / (float)( Rates.size());
}

bool Film::isStrong(){ return rate>=8; }
bool Film::isNormal(){ return rate<8 && rate>=5; }
bool Film::isWeak(){ return rate < 5 && rate>=0 ; }
int Film::showCommentorOfThisCm(int j){
    return comments[j]->showCommenter();
}
int Film::numOfBuyer(){ return numOfBuyers; }
bool Film::hasThisCmId(int cmID){
    for (int i=0;i<comments.size();i++)
        if (comments[i]->showCommentId() == cmID)
            return true;
}
int Film::whichFilmHasThisId(int filmID,vector<Film*> films){
    for (int i=0;films.size();i++)
        if (films[i]->ShowFilmId() == filmID)
            return i;
}