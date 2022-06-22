#include "user.h"
#include <iostream>
using namespace std;

User::User(string _name,string _email,string pass,int _age, int _publisher, int insystem,int _id){
    email = _email;
    userName = _name;
    password = pass;
    age = _age;
    is_publisher = _publisher;
    inSystem = insystem;   
    userID = _id;
}
int User::showFollowerId(int i){return followers[i]->showUserID(); }
string User::showFollowerName(int i){return followers[i]->showUserName();}
string User::showFollowerEmail(int i){return followers[i]->showEmail(); }
int User::numOfFollowers(){return followers.size();}
int User::showIsPublisher(){ return is_publisher;}
string User::showUserName(){ return userName; }
string User::showPassword() { return password;}
string User::showEmail(){return email; }
int User::showAge(){return age;}
int User::showInSystem(){ return inSystem; }
int User::showUserID(){return userID; }
void User::setInSystem(){inSystem = 1;}
void User::setOutSystem(){inSystem = 0; }
int User::numOfCommentsOfThisFilm(int i) { return filmsPublished[i]->num_of_comments();  }
int User::numOfNotfs(){ return notifications.size();}
int User::numOfUnseenNotfs(){return unSeenNotfs.size();}
bool User::isUnSeen(int i){return unSeenNotfs[i] == 1; }

string User::showFollowingName(int i){ return followings[i]->showUserName(); }

int User::numOfFollowings(){ return followings.size(); }

void User::addFilms(string publisher,string movieName,string summary,
  string director,int year,int length, int price,int _id,int publisherid){
    filmsPublished.push_back(new Film(publisher,movieName,summary,
     director,year, length, price,_id,publisherid));
}

void User::PushBackFollower(string name,string email, string pass,
 int _age,int _publisher,int insystem, int _id){
    followers.push_back(new User(name,email,pass,_age,_publisher,insystem,_id));
}

int User::showWhichFilmHasThisId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return i;
}

int User::numOfMsgsOfThisFilmId(int filmID, int j){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->numOfMsgsOfThisCm(j);
}

int User::numOfCommentsOfThisFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->num_of_comments();
}

void User::pushBackComment(int comment_id,string film_name,int film_id,
 string Message,int commenter , int i){
    filmsPublished[i]->newComment(comment_id,film_name,film_id,Message,commenter);
}
void User::setSeenThisNotf(int i){
    unSeenNotfs[i] = 0;
}

int User::showPublisherIdWithFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showPublisherId();
}

string User::showNotf(int i){
    return notifications[i];
}

int User::showMoney(){
    totalMoney = chargedMoney + money;
    return totalMoney;
}
void User::PushBackFollowing(string name,string email, string pass, int _age,
 int _publisher,int insystem, int _id){
    followings.push_back(new User(name,email,pass,_age,_publisher,insystem,_id));
}

void User::PushBackNotf(string str){
    notifications.push_back(str);
    unSeenNotfs.push_back(1);
}

Film* User::returnFilms(int i){ return filmsPublished[i];}
Film* User::returnFilmsPurchased(int i) { return filmsBought[i]; }

int User::showFilmId(int i){ return filmsPublished[i]->ShowFilmId(); }

int User::showFilmBoughtId(int i){ return filmsBought[i]->ShowFilmId(); }

string User::showPublisher(){return userName; }
int User::numOfFilms(){return filmsPublished.size();}
void User::changeMovieName(string _name,int whichfilm){
    filmsPublished[whichfilm]->changeName(_name);
}
void User::changeMovieYear(int _year, int whichfilm){
    filmsPublished[whichfilm]->changeYear(_year);
}
void User::changeMovieDirector(string _director,int whichfilm){
    filmsPublished[whichfilm]->changeDirector(_director);
}

void User::changeMovieLength(int _length, int whichfilm){
    filmsPublished[whichfilm]->changeLength(_length);
}

void User::changeMovieSummary(string _summary,int whichfilm){
    filmsPublished[whichfilm]->changeSummary(_summary);
}

int User::showFilmPricee(int i){ return filmsPublished[i]->showPrice(); }

void User::addSalary(int i){
    if (thisFilmIsStrong(i))
        money += 0.95 * filmsPublished[i]->showPrice();
    if (thisFilmIsNormal(i))
        money += 0.9 * filmsPublished[i]->showPrice();
    if (thisFilmIsWeak(i))
        money += 0.8 * filmsPublished[i]->showPrice();  
}

void User::costMoneyOfAdmin(float percent, int price){
    money -= percent * price;
}

void User::addChargedMoney(int _money){
    chargedMoney += _money;
}

void User::Delete_Film_ID(int id){
    for (int i=0;i<filmsPublished.size();i++){
        if (filmsPublished[i]->ShowFilmId() == id)
            filmsPublished[i]->gotDeleted();
    }
}

bool User::filmIsStrong(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            if (filmsPublished[i]->isStrong())
                return true;
}

bool User::filmIsNormal(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            if (filmsPublished[i]->isNormal())
                return true;
}
bool User::filmIsWeak(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            if (filmsPublished[i]->isWeak())
                return true;
}

bool User::thisFilmIsStrong(int i){
    return filmsPublished[i]->isStrong();
}
bool User::thisFilmIsNormal(int i){
    return filmsPublished[i]->isNormal();
}
bool User::thisFilmIsWeak(int i){
    return filmsPublished[i]->isWeak();
}


bool User::thisFilmHasntDeleted(int i){ return filmsPublished[i]->IsAvailble();}

bool User::thisFilmIsAvailble(int id){
    for (int i=0;i<filmsPublished.size();i++){
        if (filmsPublished[i]->ShowFilmId() == id && filmsPublished[i]->IsAvailble())
            return true;
    }
}

bool User::showNameFilm(string movieName){
    for (int i=0;i<filmsPublished.size();i++){
        if (filmsPublished[i]->showName() == movieName)
            return true;
    }
}

void User::addAmountMoney(int _money){
    money += _money;
}

int User::WhichFilmHasThisID(int Film_ID){
    for (int i=0;i<filmsPublished.size();i++){
        if (filmsPublished[i]->ShowFilmId() == Film_ID)
            return i;
    }
}

int User::firstRateFilm(){
    int rankRate = 0;
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->showRate() >= rankRate)
            rankRate = filmsPublished[i]->showRate();
    return rankRate;        
}


bool User::thisFilmIdHasThisCmId(int filmID, int cmID){
    return filmsPublished[WhichFilmHasThisID(filmID)]->hasThisCmId(cmID);
}

bool User::thisFilmIdExists(int idFilm){
    for (int i=0;i<filmsPublished.size();i++){
        if (idFilm == filmsPublished[i]->ShowFilmId())
            return true;
    }
}

void User::addBuyListFilms(string publisher,string movieName,
 string summary,string director,int year,
 int length, int price,int _id,int publisehrid){
    filmsBought.push_back(new Film(publisher,movieName,summary,
     director,year, length, price,_id,publisehrid));
}

bool User::hasBougthThis2Films(int i,int j){
    for (int a=0;a<filmsBought.size();a++)
        for (int b=0;b<filmsBought.size();b++)
            if (i == filmsBought[a]->ShowFilmId())
                if (j == filmsBought[b]->ShowFilmId())
                    return true;
}

void User::setNetworkMoneyToMoney(int _money){
    money = _money;
}

int User::showPriceFilm(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showPrice();
}

int User::showNumOfBuyersOfThisFilm(int i) { return filmsPublished[i]->numOfBuyer(); }

void User::costMoney(int _money) { money -= _money; }
string User::showPublisherOfFilmWithFilmID(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showPublisherName();
}

string User::showNameFilmwithFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showName();
}

string User::showSummaryWithFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showSummary();
}

float User::showRateWithFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showRate();    
}

string User::showDirectorWithFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showDirector();
}

int User::showYearWithFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showYear();
}

string User::showCm(int i, int j, int filmID){
    return filmsPublished[WhichFilmHasThisID(filmID)]->showCM(i,j);
}

int User::showLengthWithFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showLength();
}

void User::setUnavailbleThisComment(int commentID,int filmID){
   filmsPublished[WhichFilmHasThisID(filmID)]->setThisCommentIDUnavailble(commentID);
}

void User::setMoneyToZero() { money = 0; }

bool User::thisCmAvailble(int filmID, int commentID){
    return filmsPublished[WhichFilmHasThisID(filmID)]->thisCmIsAvailble(commentID);
}

bool User::thisUserHasThisCmId(int commentID, int filmID){
    for (int i=0;i<filmsPublished[WhichFilmHasThisID(filmID)]->num_of_comments();i++)
        if (filmsPublished[WhichFilmHasThisID(filmID)]->showCommentId(i) == commentID)
            return true; 
}

int User::whichUserHasThisCmId(int cmID){
    for (int i=0;i<filmsPublished.size();i++)
        for (int j=0;j<filmsPublished[i]->num_of_comments();j++)
            if (filmsPublished[i]->showCommentId(j) == cmID){
                return filmsPublished[i]->showCommentorOfThisCm(j);
            }
}


void User::addRateToMovie(int filmID, float rate, int userID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            filmsPublished[i]->addRate(rate,userID);
    for (int i=0;i<filmsBought.size();i++)
        if (filmsBought[i]->ShowFilmId() == filmID)
            filmsBought[i]->addRate(rate,userID);
}

int User::showWhichFilmBoughtHasThisId(int filmID){
    for (int i=0;i<filmsBought.size();i++)
        if (filmsBought[i]->ShowFilmId() == filmID)
            return i;
}

int User::numOfBoughtFilms(){ return filmsBought.size(); }

int User::showWhichFilmHasThisCmId(int filmID, int CmID){
    for (int i=0;i<filmsPublished.size();i++)
        for (int j=0;j<filmsPublished[i]->num_of_comments();j++)
            if (filmsPublished[i]->ShowFilmId() == filmID)
                if (filmsPublished[i]->showCommentId(j))
                    return i;
}

void User::PushBackReplyCmMessage(string str,int filmID, int cmID){
    filmsPublished[showWhichFilmHasThisCmId(filmID, cmID)]->
     pushBackReplyMessage
      (filmsPublished[showWhichFilmHasThisCmId(filmID,cmID)]->whichCommentsHasThisId(cmID),str);
}

int User::showCmId(int i, int filmID){
    return filmsPublished[WhichFilmHasThisID(filmID)]->showCommentId(i);
}