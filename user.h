#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "film.h"

class User{
public:
    User(std::string _name,std::string _email,std::string pass,int _age, int _publisher,int insystem,int _id);
    void PushBackFollower(std::string name,std::string email, std::string pass, int _age,int _publisher,int insystem, int _id);
    void PushBackFollowing(std::string name,std::string email, std::string pass, int _age,int _publisher,int insystem, int _id);
    int showIsPublisher();
    std::string showUserName();
    std::string showPassword();
    int showInSystem();
    void setInSystem();
    void setOutSystem();
    void addFilms(std::string publisher,std::string movieName,std::string summary, std::string director,
     int year,int length, int price,int _id, int publisherid);
    std::string showPublisher();
    void changeMovieName(std::string _name, int whichfilm);
    void changeMovieDirector(std::string _director, int whichfilm);
    void changeMovieYear(int _year,int whichfilm);
    void changeMovieLength(int _length,int whichfilm);
    void changeMovieSummary(std::string _summary, int whichfilm);
    int numOfFilms();
    void Delete_Film_ID(int id);
    bool thisFilmIsAvailble(int id);
    bool showNameFilm(std::string movieName);
    void addAmountMoney(int _money);
    int WhichFilmHasThisID(int Film_ID);
    bool thisFilmIdExists(int idFilm);
    std::string showEmail();
    int showAge();
    int showUserID();
    int numOfFollowers();
    int numOfFollowings();
    std::string showFollowingName(int i);
    std::string showFollowerName(int i);
    int showFollowerId(int i);
    std::string showFollowerEmail(int i);
    void PushBackNotf(std::string str);
    int numOfNotfs();
    int numOfUnseenNotfs();
    bool isUnSeen(int i);
    void setSeenThisNotf(int i);
    std::string showNotf(int i);
    void addBuyListFilms(std::string publisher,std::string movieName,std::string summary, std::string director,
     int year,int length, int price,int _id,int publisherid);
    int showPriceFilm(int filmID);
    int showMoney(); 
    int showFilmId(int i);
    void costMoney(int _money);
    std::string showPublisherOfFilmWithFilmID(int filmID);
    std::string showNameFilmwithFilmId(int filmID);
    std::string showSummaryWithFilmId(int filmID);
    std::string showDirectorWithFilmId(int filmID);
    float showRateWithFilmId(int filmID);
    int showYearWithFilmId(int filmID);
    int showLengthWithFilmId(int filmID);
    int showPublisherIdWithFilmId(int filmID);
    void pushBackComment(int comment_id,std::string film_name,int film_id,std::string Message,int commenter, int i);
    int numOfCommentsOfThisFilm(int i);
    int showWhichFilmHasThisId(int filmID);
    void setUnavailbleThisComment(int commentID, int filmID);
    bool thisCmAvailble(int filmID, int commentID);
    bool thisUserHasThisCmId(int commentID, int filmID);
    void addRateToMovie(int filmID,float rate, int userID);
    int showWhichFilmBoughtHasThisId(int filmID);
    int numOfBoughtFilms();
    int showFilmBoughtId(int i);
    bool thisFilmIsStrong(int i);
    bool thisFilmIsNormal(int i);
    bool thisFilmIsWeak(int i);
    void addSalary(int i);
    int showWhichFilmHasThisCmId(int filmID, int CmID);
    void PushBackReplyCmMessage(std::string str,int filmID, int cmID);
    int whichUserHasThisCmId(int cmID);
    bool thisFilmIdHasThisCmId(int filmID, int cmID);
    int firstRateFilm();
    Film* returnFilms(int i);
    Film* returnFilmsPurchased(int i);
    std::string showCm(int i, int j, int filmID);
    int numOfCommentsOfThisFilmId(int filmID);
    int numOfMsgsOfThisFilmId(int filmID, int j);
    void setMoneyToZero();
    int showCmId(int i, int filmID);
    bool thisFilmHasntDeleted(int i);
    int showFilmPricee(int i);
    int showNumOfBuyersOfThisFilm(int i);
    bool hasBougthThis2Films(int i,int j);
    void setNetworkMoneyToMoney(int _money);
    void costMoneyOfAdmin(float percent,int price);
    bool filmIsStrong(int filmID);
    bool filmIsNormal(int filmID);
    bool filmIsWeak(int filmID);
    void addChargedMoney(int _money);
protected:
    int userID;
    std::string userName;
    std::string email;
    std::string password;
    int totalMoney = 0;
    int chargedMoney = 0;
    int money = 0;
    int age;
    int is_publisher = 0;
    int inSystem = 0;
    std::vector<Film*> filmsPublished;
    std::vector<Film*> filmsBought;
    std::vector<std::string> notifications;
    std::vector<int> unSeenNotfs;
    std::vector<User*> followings;
    std::vector<User*> followers;
};

#endif