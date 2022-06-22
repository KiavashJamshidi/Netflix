#include "publisher.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Publisher::Publisher(string _name,string _email,string pass,int _age,
  int _publisher, int insystem,int _id) 
: User(_name,_email,pass,_age,_publisher,insystem,_id) {}


int Publisher::showFilmId(int i){ return filmsPublished[i]->ShowFilmId(); }

int Publisher::showFilmBoughtId(int i){ return filmsBought[i]->ShowFilmId(); }

string Publisher::showPublisher(){return userName; }
void Publisher::changeMovieName(string _name,int whichfilm){
    filmsPublished[whichfilm]->changeName(_name);
}
void Publisher::changeMovieYear(int _year, int whichfilm){
    filmsPublished[whichfilm]->changeYear(_year);
}
void Publisher::changeMovieDirector(string _director,int whichfilm){
    filmsPublished[whichfilm]->changeDirector(_director);
}

void Publisher::changeMovieLength(int _length, int whichfilm){
    filmsPublished[whichfilm]->changeLength(_length);
}

void Publisher::changeMovieSummary(string _summary,int whichfilm){
    filmsPublished[whichfilm]->changeSummary(_summary);
}

void Publisher::Delete_Film_ID(int id){
    for (int i=0;i<filmsPublished.size();i++){
        if (filmsPublished[i]->ShowFilmId() == id)
            filmsPublished[i]->gotDeleted();
    }
}
bool Publisher::thisFilmIsStrong(int i){ return filmsPublished[i]->isStrong(); }
bool Publisher::thisFilmIsNormal(int i){ return filmsPublished[i]->isNormal(); }
bool Publisher::thisFilmIsWeak(int i){ return filmsPublished[i]->isWeak(); }

void Publisher::costMoney(int _money) { money -= _money; }
string Publisher::showPublisherOfFilmWithFilmID(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showPublisherName();
}

string Publisher::showNameFilmwithFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showName();
}

string Publisher::showSummaryWithFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showSummary();
}

int Publisher::showRateWithFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showRate();    
}

string Publisher::showDirectorWithFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showDirector();
}

int Publisher::showYearWithFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showYear();
}

int Publisher::showLengthWithFilmId(int filmID){
    for (int i=0;i<filmsPublished.size();i++)
        if (filmsPublished[i]->ShowFilmId() == filmID)
            return filmsPublished[i]->showLength();
}

void Publisher::setUnavailbleThisComment(int commentID,int filmID){
   filmsPublished[WhichFilmHasThisID(filmID)]->setThisCommentIDUnavailble(commentID);
}

bool Publisher::thisCmAvailble(int filmID, int commentID){
    return filmsPublished[WhichFilmHasThisID(filmID)]->thisCmIsAvailble(commentID);
}

bool Publisher::thisUserHasThisCmId(int commentID, int filmID){
    for (int i=0;i<filmsPublished[WhichFilmHasThisID(filmID)]->num_of_comments();i++)
        if (filmsPublished[WhichFilmHasThisID(filmID)]->showCommentId(i) == commentID)
            return true; 
}

int Publisher::showWhichFilmBoughtHasThisId(int filmID){
    for (int i=0;i<filmsBought.size();i++)
        if (filmsBought[i]->ShowFilmId() == filmID)
            return i;
}

int Publisher::numOfBoughtFilms(){ return filmsBought.size(); }