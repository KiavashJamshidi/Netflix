#ifndef FILM_H
#define FILM_H
#include <string>
#include <vector>
#include "comment.h"
#include <map>
class Film{
public:
    Film(std::string _publisher, std::string _movieName,std::string _summary,
     std::string _director,int _year, int _length, int _price,int _idd, int publisherID);
    void changeName(std::string _name);
    void changeYear(int _year);
    void changeLength(int _length);
    void changeSummary(std::string _summary);
    void changeDirector(std::string _director); 
    std::string showName();
    void gotDeleted();
    bool IsAvailble();
    int ShowFilmId();
    int showPrice();
    int showPublisherId();
    std::string showPublisherName();
    std::string showDirector();
    std::string showSummary();
    int showYear();
    int showLength();
    float showRate();
    int showIsAvailble();
    void newComment(int comment_id,std::string film_name,int film_id,std::string Message,int commenter);
    int num_of_comments();
    bool thisCmIsAvailble(int comment_id);
    void setThisCommentIDUnavailble(int comment_id);
    int showCommentId(int i);
    void addRate(int _rate, int userID);
    bool isStrong();
    bool isNormal();
    bool isWeak();
    void pushBackReplyMessage(int i,std::string str);
    int whichCommentsHasThisId(int cmID);
    int showCommentorOfThisCm(int j);
    bool hasThisCmId(int cmID);
    std::string showCM(int cm, int msg);
    int numOfMsgsOfThisCm(int j);
    int whichFilmHasThisId(int filmID,std::vector<Film*> films);
    int numOfBuyer();
    void addBuyersNum();
private:
    std::map<int,int> Rates;
    std::string PublisherName;
    int PublisherID;
    std::string MovieName;
    std::string director;
    std::string summary;
    int numOfBuyers = 0;
    int filmID;
    int year;
    int length;
    float rate = 0.00;
    int numOfVoters = 0;
    int sumOfRates = 0;
    int price;
    int is_Availble = 1;
    std::vector<Comment*> comments;
};

#endif