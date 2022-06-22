#ifndef PUBLISHER_H
#define PUBLISHER_H
#include "user.h"
#include <string>
#include <vector>

class User;
class Publisher : public User{
public:
    Publisher(std::string _name,std::string _email,std::string pass,int _age, int _publisher,int insystem,int _id);
    void PushBackFollower(std::string name,std::string email, std::string pass, int _age,int _publisher,int insystem, int _id);
    void PushBackFollowing(std::string name,std::string email, std::string pass, int _age,int _publisher,int insystem, int _id);
    int showIsPublisher();
    std::string showPublisher();
    void changeMovieName(std::string _name, int whichfilm);
    void changeMovieDirector(std::string _director, int whichfilm);
    void changeMovieYear(int _year,int whichfilm);
    void changeMovieLength(int _length,int whichfilm);
    void changeMovieSummary(std::string _summary, int whichfilm);
    void Delete_Film_ID(int id);
    int showFilmId(int i);
    void costMoney(int _money);
    std::string showPublisherOfFilmWithFilmID(int filmID);
    std::string showNameFilmwithFilmId(int filmID);
    std::string showSummaryWithFilmId(int filmID);
    std::string showDirectorWithFilmId(int filmID);
    int showRateWithFilmId(int filmID);
    int showYearWithFilmId(int filmID);
    int showLengthWithFilmId(int filmID);
    int showPublisherIdWithFilmId(int filmID);
    void pushBackComment(int comment_id,std::string film_name,int film_id,std::string Message,int commenter, int i);
    int numOfCommentsOfThisFilm(int i);
    int showWhichFilmHasThisId(int filmID);
    void setUnavailbleThisComment(int commentID, int filmID);
    bool thisCmAvailble(int filmID, int commentID);
    bool thisUserHasThisCmId(int commentID, int filmID);
    void addRateToMovie(int filmID,float rate);
    int showWhichFilmBoughtHasThisId(int filmID);
    int numOfBoughtFilms();
    int showFilmBoughtId(int i);
    bool thisFilmIsStrong(int i);
    bool thisFilmIsNormal(int i);
    bool thisFilmIsWeak(int i);
    void addSalary(int i);
private:
    int isPublisher = 1;
};
#endif