#include "netflix.h"
#include "exception.h"
#include <iostream>
#include <string> 
#include <algorithm>
#include "hash.h"
#include "defines.h"

using namespace std;

NetflixSystem::~NetflixSystem(){
    for (int i=0;i<users.size();i++)
        delete users[i];
}

NetflixSystem::NetflixSystem(std::string email,std::string username,std::string pass,int age,
 int publisher, int insystem){
    users.push_back(new User(username,email,pass,age,publisher,0,0));
}


void NetflixSystem::pushBackUser(string name, string email, string pass, int age,
 int publisher, int insystem){ 
    users.push_back(new User(name,email,pass,age,publisher,1,users.size()));
}

bool NetflixSystem::checkEmailSyntax(string name){
    int atsign=0;
    int dot = 0;
    for (int i=0;i<name.size();i++){
        if (name[i] == '@')
            atsign++;
        if (name[i] == '.')
            dot++;    
    }
    return atsign == 1 && dot == 1;
}

bool NetflixSystem::noOneIsInSystem(){
    int test = 0;
    for (int i=0;i<users.size();i++)
        if (users[i]->showInSystem() == 1)
            test = 1;
    return test == 0;        
}

string NetflixSystem::firstString(string line){
    string name = "";
    for (int i=0;i<line.size();i++){
        if (line[i] != ' ')
            name+=line[i];
        if (line[i]== ' ' && line[i-1]!=' ' && i != 0 )
            break;     
    }
    return name;
}
string NetflixSystem::showUserNameWithID(int User_id){
    for (int i=0;i<users.size();i++)
        if (users[i]->showUserID() == User_id)
            return users[i]->showUserName();
}
string NetflixSystem::showMailWithUserID(int User_id){
    for (int i=0;i<users.size();i++)
        if (users[i]->showUserID() == User_id)
            return users[i]->showEmail();
}
string NetflixSystem::showPassWithID(int User_id){
    for (int i=0;i<users.size();i++)
        if (users[i]->showUserID() == User_id)
            return users[i]->showPassword();
}
int NetflixSystem::showAgeWithID(int User_id){
    for (int i=0;i<users.size();i++)
        if (users[i]->showUserID() == User_id)
            return users[i]->showAge();
}
int NetflixSystem::showIsPublisherWithID(int User_id){
    for (int i=0;i<users.size();i++)
        if (users[i]->showUserID() == User_id)
            return users[i]->showIsPublisher();
}

bool NetflixSystem::thisStrExists(string line,string str){
    for (int i=1;i<line.size();i++)
        if (line.substr(i,str.size())==str)
            return true;
}

int NetflixSystem::whoIsInSystem(){
    for (int i=0;i<users.size();i++)
        if (users[i]->showInSystem() == 1)
            return i;
}

string NetflixSystem::showPublisherOfThisFilm(int filmID){
    for (int i=0;i<users.size();i++)
        for (int j=0;j<users[i]->numOfFilms();j++)
            if (users[i]->showFilmId(j) == filmID)
                return users[i]->showPublisherOfFilmWithFilmID(filmID);
}

string NetflixSystem::showDirectorOfThisFilm(int filmID){
    for (int i=0;i<users.size();i++)
        for (int j=0;j<users[i]->numOfFilms();j++)
            if (users[i]->showFilmId(j) == filmID)
                return users[i]->showDirectorWithFilmId(filmID);
}

int NetflixSystem::showYearOfThisFilm(int filmID){
    for (int i=0;i<users.size();i++)
        for (int j=0;j<users[i]->numOfFilms();j++)
            if (users[i]->showFilmId(j) == filmID)
                return users[i]->showYearWithFilmId(filmID);
}

int NetflixSystem::showWhichUserHasCommentorID(int cmID , int who){
        return (users[who]->whichUserHasThisCmId(cmID));
}

int NetflixSystem::showLengthOfThisFilm(int filmID){
    for (int i=0;i<users.size();i++)
        for (int j=0;j<users[i]->numOfFilms();j++)
            if (users[i]->showFilmId(j) == filmID)
                return users[i]->showLengthWithFilmId(filmID);
}

int NetflixSystem::showSystemMoney(){ return systemMoney; }

string NetflixSystem::showMovieNameOfThisFilm(int filmID){
    for (int i=0;i<users.size();i++)
        for (int j=0;j<users[i]->numOfFilms();j++)
            if (users[i]->showFilmId(j) == filmID)
                return users[i]->showNameFilmwithFilmId(filmID);
}

bool NetflixSystem::thisFilmHastThisCmId(int filmID, int cmID, int who){
    return users[who]->thisFilmIdHasThisCmId(filmID, cmID);
}

void NetflixSystem::setUserOnline(int i){
    users[i]->setInSystem();
}

void NetflixSystem::setAllUsersOff(){
    for (int i = 0;i < users.size();i++)
        users[i]->setOutSystem();
}

int NetflixSystem::whoLoggedIn(string line){
    for (int i=0;i<users.size();i++)
        if (whatYouWant(line,USERNAME) == users[i]->showUserName() && whatYouWant(line,PASSWORD) ==
         users[i]->showPassword())
            return i;
}

bool NetflixSystem::isTwoCommands(string line){
    return firstString(line) == GET 
    || firstString(line) == POST;
}

void NetflixSystem::addMoneyToSystem(int money){
    systemMoney += money;
}

bool NetflixSystem::isPublisher(int i){return users[i]->showIsPublisher() == 1;}

bool NetflixSystem::userExists(string wantSignUp){
    for (int i=0;i<users.size();i++)
        if (wantSignUp == users[i]->showUserName())
            return true;
}

int NetflixSystem::showPriceOfThisFilm(int filmID){
    for (int i=0;i<users.size();i++)
        for (int j=0;j<users[i]->numOfFilms();j++)
            if (users[i]->showFilmId(j) == filmID)
                return users[i]->showPriceFilm(filmID);
}

string NetflixSystem::showSummaryOfThisFilm(int filmID){
    for (int i=0;i<users.size();i++)
        for (int j=0;j<users[i]->numOfFilms();j++)
            if (users[i]->showFilmId(j) == filmID)
                return users[i]->showSummaryWithFilmId(filmID);
}

int NetflixSystem::howManySpace(string line){
    int numSpace = 0;
    if (line[0] == ' ')
        numSpace--;
    for (int i = 1; i <line.size() - 1;i++)
        if ((line[i] == ' ' && line[i-1] != ' ' && line[i+1]!= ' ') ||
         (line[i]==' ' && line[i+1] !=' ' &&line[i-1]==' '))
            numSpace++;
    return numSpace;
}

int NetflixSystem::firstChar(string line,string str){
    for (int i = 0;i<line.size();i++){
        if (line.substr(i,str.size()) == str && line[i+str.size()] == ' '){
            int j=1;
            for (j;j<line.size();j++)
                if (line[i+str.size()+j] != ' '){
                    return i + str.size() + j;
                    break;
                }
        }
    }
}

int NetflixSystem::lastChar(string line, int i){
    for (i;i<line.size();i++)
        if (line[i]==' ')
            return i-1;
}

bool NetflixSystem::forRateOrCmThisFilmHasBougth(int who, int filmID){
    for (int i=0;i<users[who]->numOfBoughtFilms();i++)
        if (users[who]->showFilmBoughtId(i) == filmID) 
            return true;
}


string NetflixSystem::whatYouWant(string line,string str){
    return line.substr(firstChar(line,str),lastChar(line,firstChar(line,str))
     + 1 - firstChar(line,str));
}

bool NetflixSystem::thisCmIsAvailble(int filmID, int cmID){
        if (users[showWhichUserWithFilmId(filmID)]->thisCmAvailble(filmID, cmID))
            return true;
}

bool NetflixSystem::userMatchPassword(string line){
    HashMd5 hash;
    string pass;
    hash.update(whatYouWant(line,PASSWORD).begin(), whatYouWant(line,PASSWORD).end());
    hash.hex_digest(pass);
    for (int i=0;i<users.size();i++)
        if (whatYouWant(line,USERNAME) == users[i]->showUserName() 
         && whatYouWant(line,PASSWORD) == users[i]->showPassword())
            return true;
}

void NetflixSystem::logOut(string line){
    if (users.size()==0) throw BadRequest();
    if (noOneIsInSystem()) throw BadRequest();
    if (howManySpace(line)!= 1) throw BadRequest();
    setAllUsersOff();
    cout << OK << endl;
}

void NetflixSystem::filterFilmsPublished(string line){
    if (users.size() == 0 || noOneIsInSystem()) throw PermissionDenied();
    if (!isPublisher(whoIsInSystem())) throw PermissionDenied();
    if (howManySpace(line) < 1 || howManySpace(line) > 14) throw BadRequest();
    vector<Film*> filmsPublishedfilter;
    for (int i=0;i<users[whoIsInSystem()]->numOfFilms();i++)
        filmsPublishedfilter.push_back(users[whoIsInSystem()]->returnFilms(i));
    if (thisStrExists(line,NAME))
        for (int i=0;i<filmsPublishedfilter.size();i++)
            if (filmsPublishedfilter[i]->showName() != whatYouWant(line,NAME)){
                filmsPublishedfilter.erase(filmsPublishedfilter.begin() + i);
                i--;
            }
    if (thisStrExists(line,PRICE))
        for (int i=0;i<filmsPublishedfilter.size();i++)
            if (filmsPublishedfilter[i]->showPrice() != stoi(whatYouWant(line,PRICE))){
                filmsPublishedfilter.erase(filmsPublishedfilter.begin() + i);
                i--;
            }
    if (thisStrExists(line,DIRECTOR))
        for (int i=0;i<filmsPublishedfilter.size();i++)
            if (filmsPublishedfilter[i]->showDirector() != whatYouWant(line,DIRECTOR)){
                filmsPublishedfilter.erase(filmsPublishedfilter.begin() + i);
                i--;
            }
    if (thisStrExists(line,MAX_YEAR))
        for (int i=0;i<filmsPublishedfilter.size();i++)
            if (filmsPublishedfilter[i]->showYear() > stoi(whatYouWant(line,MAX_YEAR))){
                filmsPublishedfilter.erase(filmsPublishedfilter.begin() + i);
                i--;
            }
    if (thisStrExists(line,MIN_YEAR))
        for (int i=0;i<filmsPublishedfilter.size();i++)
            if (filmsPublishedfilter[i]->showYear() < stoi(whatYouWant(line,MIN_YEAR))){
                filmsPublishedfilter.erase(filmsPublishedfilter.begin() + i);
                i--;
            }
    if (thisStrExists(line,MIN_RATE))
        for (int i=0;i<filmsPublishedfilter.size();i++)
            if (filmsPublishedfilter[i]->showRate() < stoi(whatYouWant(line,MIN_RATE))){
                filmsPublishedfilter.erase(filmsPublishedfilter.begin() + i);
                i--;
            }
    for (int i=0;i<filmsPublishedfilter.size();i++)
        if (!filmsPublishedfilter[i]->IsAvailble()){
            filmsPublishedfilter.erase(filmsPublishedfilter.begin() + i);
            i--;
        }
    cout << TITLE_FILTER_PUBLISHED << endl;
    for (int i=0;i<filmsPublishedfilter.size();i++)
        cout <<  i+1 << ". " << filmsPublishedfilter[i]->ShowFilmId() << " | " <<
         filmsPublishedfilter[i]->showName()
            << " | " << filmsPublishedfilter[i]->showLength() << " | " <<
             filmsPublishedfilter[i]->showPrice() << " | " <<
             filmsPublishedfilter[i]->showRate()
            << " | " << filmsPublishedfilter[i]->showYear() << " | " <<
             filmsPublishedfilter[i]->showDirector() << endl;
    filmsPublishedfilter.clear();                 
}

void NetflixSystem::filterAllFilms(string line){
    if (users.size() == 0|| noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line) < 1 || howManySpace(line) > 14) throw BadRequest();
    vector<Film*> filmsPublishedEveryone;
    for (int num=0;num<users.size();num++){
        if (isPublisher(num)){
            for (int i=0;i<users[num]->numOfFilms();i++)
                filmsPublishedEveryone.push_back(users[num]->returnFilms(i));
        }
    }
    if (thisStrExists(line,NAME))
        for (int i=0;i<filmsPublishedEveryone.size();i++)
            if (filmsPublishedEveryone[i]->showName() != whatYouWant(line,NAME)){
                filmsPublishedEveryone.erase(filmsPublishedEveryone.begin() + i);
                i--;
            }
    if (thisStrExists(line,PRICE))
        for (int i=0;i<filmsPublishedEveryone.size();i++)
            if (filmsPublishedEveryone[i]->showPrice() != stoi(whatYouWant(line,PRICE))){
                filmsPublishedEveryone.erase(filmsPublishedEveryone.begin() + i);
                i--;
            }
    if (thisStrExists(line,DIRECTOR))
        for (int i=0;i<filmsPublishedEveryone.size();i++)
            if (filmsPublishedEveryone[i]->showDirector() != whatYouWant(line,DIRECTOR)){
                filmsPublishedEveryone.erase(filmsPublishedEveryone.begin() + i);
                i--;
            }
    if (thisStrExists(line,MAX_YEAR))
        for (int i=0;i<filmsPublishedEveryone.size();i++)
            if (filmsPublishedEveryone[i]->showYear() > stoi(whatYouWant(line,MAX_YEAR))){
                filmsPublishedEveryone.erase(filmsPublishedEveryone.begin() + i);
                i--;
            }
    if (thisStrExists(line,MIN_YEAR))
        for (int i=0;i<filmsPublishedEveryone.size();i++)
            if (filmsPublishedEveryone[i]->showYear() < stoi(whatYouWant(line,MIN_YEAR))){
                filmsPublishedEveryone.erase(filmsPublishedEveryone.begin() + i);
                i--;
            }
    if (thisStrExists(line,MIN_RATE))
        for (int i=0;i<filmsPublishedEveryone.size();i++)
            if (filmsPublishedEveryone[i]->showRate() < stoi(whatYouWant(line,MIN_RATE))){
                filmsPublishedEveryone.erase(filmsPublishedEveryone.begin() + i);
                i--;
            }
    for (int i=0;i<filmsPublishedEveryone.size();i++)
        if (!filmsPublishedEveryone[i]->IsAvailble()){
            filmsPublishedEveryone.erase(filmsPublishedEveryone.begin() + i);
            i--;
        }
    cout << TITLE_FILTER_PUBLISHED << endl;
    sort(filmsPublishedEveryone.begin(), filmsPublishedEveryone.end(), [](Film* a, Film *b){
        return a->ShowFilmId() < b->ShowFilmId();
    });
    for (int i=0;i<filmsPublishedEveryone.size();i++)
        cout <<  i+1 << ". " << filmsPublishedEveryone[i]->ShowFilmId() << " | " << 
        filmsPublishedEveryone[i]->showName()
            << " | " << filmsPublishedEveryone[i]->showLength() << " | " << 
            filmsPublishedEveryone[i]->showPrice() << " | " <<
            filmsPublishedEveryone[i]->showRate()
            <<  " | " <<filmsPublishedEveryone[i]->showYear() << " | " <<
             filmsPublishedEveryone[i]->showDirector() << endl;

    filmsPublishedEveryone.clear();                 
}

void NetflixSystem::signUp(string line){
    if (!noOneIsInSystem()) throw BadRequest();
    if (userExists(whatYouWant(line,USERNAME))) throw BadRequest();
    if (howManySpace(line) < 10 || howManySpace(line) == 11 || howManySpace(line) > 12) throw BadRequest();
    if (!checkEmailSyntax(whatYouWant(line,EMAIL))) throw BadRequest();
    if (!thisStrExists(line,USERNAME) || !thisStrExists(line,EMAIL) || !thisStrExists(line,PASSWORD) ||
     !thisStrExists(line,AGE)) throw BadRequest();
    HashMd5 hash;
    string pass;
    if (howManySpace(line) == 10){
        setAllUsersOff();
        hash.update(whatYouWant(line,PASSWORD).begin(),whatYouWant(line,PASSWORD).end());
        hash.hex_digest(pass);
        pushBackUser(whatYouWant(line,USERNAME),whatYouWant(line,EMAIL),
            whatYouWant(line,PASSWORD),stoi(whatYouWant(line,AGE)),0,1);    
        cout << OK << endl;                
    }
    if (howManySpace(line)==12){
        if (whatYouWant(line,PUBLISHER) != TRUEE && 
         whatYouWant(line,PUBLISHER)!=FALSEE) throw BadRequest();
        if (whatYouWant(line,PUBLISHER) == TRUEE){
            setAllUsersOff();
            hash.update(whatYouWant(line,PASSWORD).begin(),whatYouWant(line,PASSWORD).end());
            hash.hex_digest(pass);
            pushBackUser(whatYouWant(line,USERNAME),whatYouWant(line,EMAIL),
                whatYouWant(line,PASSWORD),stoi(whatYouWant(line,AGE)),1,1); 
            cout << OK << endl;
        }
        if (whatYouWant(line,PUBLISHER) == FALSEE){
            setAllUsersOff();
            hash.update(whatYouWant(line,PASSWORD).begin(),whatYouWant(line,PASSWORD).end());
            hash.hex_digest(pass);
            pushBackUser(whatYouWant(line,USERNAME),whatYouWant(line,EMAIL),
                whatYouWant(line,PASSWORD),stoi(whatYouWant(line,AGE)),0,1);
            cout << OK << endl;
        } 
    }
}

void NetflixSystem::Login(string line){
    if (!noOneIsInSystem()) throw BadRequest();
    if (howManySpace(line) != 6) throw BadRequest();
    if (!thisStrExists(line,USERNAME) || !thisStrExists(line,PASSWORD)) throw BadRequest();
    if (!userExists(whatYouWant(line,USERNAME)) || !userMatchPassword(line)) throw BadRequest();
    setAllUsersOff();
    setUserOnline(whoLoggedIn(line));
    cout << OK << endl;
}

void NetflixSystem::EditFilm(string line){
    if (users.size()==0 || noOneIsInSystem()) throw PermissionDenied();
    if (!isPublisher(whoIsInSystem())) throw PermissionDenied();
    if (users[whoIsInSystem()]->thisFilmIdExists(stoi(whatYouWant(line,FILM_ID)))){
        if (howManySpace(line) < 4 || howManySpace(line) > 14) throw BadRequest();
        int tst = 0;
            if (thisStrExists(line,NAME)){
                users[whoIsInSystem()]->changeMovieName(whatYouWant(line,NAME),
                    users[whoIsInSystem()]->WhichFilmHasThisID(stoi(whatYouWant(line,FILM_ID))));
                tst = 1;
            }
            if (thisStrExists(line,YEAR)){
                users[whoIsInSystem()]->changeMovieYear(stoi(whatYouWant(line,YEAR)),
                    users[whoIsInSystem()]->WhichFilmHasThisID(stoi(whatYouWant(line,FILM_ID))));
                tst = 1;
            }
            if (thisStrExists(line,DIRECTOR)){
                users[whoIsInSystem()]->changeMovieDirector(whatYouWant(line,DIRECTOR),
                    users[whoIsInSystem()]->WhichFilmHasThisID(stoi(whatYouWant(line,FILM_ID))));
                tst = 1;
            }
            if (thisStrExists(line,LENGTH)){
                users[whoIsInSystem()]->changeMovieLength(stoi(whatYouWant(line,LENGTH)),
                    users[whoIsInSystem()]->WhichFilmHasThisID(stoi(whatYouWant(line,FILM_ID))));
                tst = 1;
            }
            if (thisStrExists(line,SUMMARY)){
                users[whoIsInSystem()]->changeMovieSummary(whatYouWant(line,SUMMARY),
                    users[whoIsInSystem()]->WhichFilmHasThisID(stoi(whatYouWant(line,FILM_ID)))); 
                tst = 1;
            }   
            if (tst == 1) cout << OK << endl;
    }
    else{
        if (stoi(whatYouWant(line,FILM_ID)) <= numOfAllFilms) throw PermissionDenied();
        else throw NotFound();
    }
}

void NetflixSystem::PostFilm(string line){
    if (users.size() == 0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line) != 14) throw BadRequest();
    if (!isPublisher(whoIsInSystem())) throw PermissionDenied();
    if (thisStrExists(line,NAME) && thisStrExists(line,LENGTH) && thisStrExists(line,YEAR) &&
     thisStrExists(line,PRICE) &&
        thisStrExists(line,SUMMARY) && thisStrExists(line,DIRECTOR)){
        users[whoIsInSystem()]->addFilms(users[whoIsInSystem()]->showPublisher()
            ,whatYouWant(line,NAME),whatYouWant(line,SUMMARY),
            whatYouWant(line,DIRECTOR),stoi(whatYouWant(line,YEAR)),
            stoi(whatYouWant(line,LENGTH)),stoi(whatYouWant(line,PRICE)),numOfAllFilms + 1,
             users[whoIsInSystem()]->showUserID());
        for (int i=0;i<users[whoIsInSystem()]->numOfFollowers();i++)
            users[i]->PushBackNotf("Publisher " + users[whoIsInSystem()]->showUserName() +
             " with id " +
            to_string(users[whoIsInSystem()]->showUserID()) + " register new film.\n"); 
        numOfAllFilms++;
        cout << OK << endl; 
    }else throw BadRequest();  
}


void NetflixSystem::deleteFilmid(string line){
    if (users.size()==0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line) != 4) throw BadRequest();
    if (!thisStrExists(line,FILM_ID)) throw BadRequest();
    if (!isPublisher(whoIsInSystem())) throw PermissionDenied();
    if (stoi(whatYouWant(line,FILM_ID)) > numOfAllFilms) throw NotFound();
    if (!users[whoIsInSystem()]->thisFilmIdExists
     (stoi(whatYouWant(line,FILM_ID)))) throw PermissionDenied();
    if (!users[whoIsInSystem()]->thisFilmIsAvailble
     (stoi(whatYouWant(line,FILM_ID)))) throw NotFound();
    users[whoIsInSystem()]->Delete_Film_ID(stoi(whatYouWant(line,FILM_ID)));
    cout << OK << endl;
}


void NetflixSystem::addMoney(string line){
    if (users.size()==0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line) != 4) throw BadRequest();
    users[whoIsInSystem()]->addChargedMoney(stoi(whatYouWant(line,AMOUNT)));
    cout << OK << endl;
}

bool NetflixSystem::thisFilmIDGotDeleted(int filmID){
    for (int i=0;i<users.size();i++)
        for (int j=0;j<users[i]->numOfFilms();j++)
            if (users[i]->showFilmId(j) == filmID)
                if (!users[i]->thisFilmIsAvailble(filmID))
                    return true;
}   

void NetflixSystem::FollowPublisher(string line){
    if (users.size()==0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line) != 4) throw BadRequest();
    if (stoi(whatYouWant(line,USER_ID))>=users.size() ||
     stoi(whatYouWant(line,USER_ID)) <= 0) throw NotFound();
    if (!isPublisher(stoi(whatYouWant(line,USER_ID)))) throw PermissionDenied();
    if (!thisStrExists(line,USER_ID)) throw BadRequest();
    int checkIsFollowing = 0;
    for (int i=0;i<users[whoIsInSystem()]->numOfFollowings();i++)
        if (showUserNameWithID(stoi(whatYouWant(line,USER_ID))) == 
         users[whoIsInSystem()]->showFollowingName(i))
            checkIsFollowing = 1;
    if (checkIsFollowing == 0){  
        users[stoi(whatYouWant(line,USER_ID))]->PushBackFollower
         (users[whoIsInSystem()]->showUserName(),
            users[whoIsInSystem()]->showEmail(),
            users[whoIsInSystem()]->showPassword(),users[whoIsInSystem()]->showAge(),
            users[whoIsInSystem()]->showIsPublisher(),1,users[whoIsInSystem()]->showUserID());
        users[whoIsInSystem()]->PushBackFollowing
         (users[stoi(whatYouWant(line,USER_ID))]->showUserName(),
            users[stoi(whatYouWant(line,USER_ID))]->showEmail(),
            users[stoi(whatYouWant(line,USER_ID))]->showUserName(),
             users[stoi(whatYouWant(line,USER_ID))]->showAge(),
            users[stoi(whatYouWant(line,USER_ID))]->showIsPublisher(),
            0,stoi(whatYouWant(line,USER_ID)));
        users[stoi(whatYouWant(line,USER_ID))]->PushBackNotf(( "User " + 
         (users[whoIsInSystem()]->showUserName()) + " with id " 
        + to_string(users[whoIsInSystem()]->showUserID()) + " follow you.\n"));    
    } 
    cout << OK << endl;
}

void NetflixSystem::showFollowers(string line){
    if (users.size()==0 || noOneIsInSystem()) throw PermissionDenied();
    if (!isPublisher(whoIsInSystem())) throw PermissionDenied();
    if (howManySpace(line)!=1) throw BadRequest();
    cout << TITLE_FOLLOWERS << endl;
    for (int i=0;i<users[whoIsInSystem()]->numOfFollowers();i++){
        cout << i+1 << ". " << users[whoIsInSystem()]->showFollowerId(i) << " | " <<
         users[whoIsInSystem()]->showFollowerName(i) 
            << " | " << users[whoIsInSystem()]->showFollowerEmail(i) << endl;
    }
}

int NetflixSystem::showWhichUserWithFilmId(int filmID){
    for (int i=0;i<users.size();i++)
        for (int j=0;j<users[i]->numOfFilms();j++)
            if (users[i]->showFilmId(j) == filmID)
                return i;
}

void NetflixSystem::showUnseenNotfs(string line){
    if (users.size() == 0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line) != 1) throw BadRequest();
    cout << TITLE_NOTFS << endl;
    int num = 1;
    for (int i=users[whoIsInSystem()]->numOfNotfs() - 1;i >= 0;i--){
        if (users[whoIsInSystem()]->isUnSeen(i)){
            cout << num << ". " << users[whoIsInSystem()]->showNotf(i);
            users[whoIsInSystem()]->setSeenThisNotf(i);
            num++;
        }
    }
}

void NetflixSystem::showSeenNotfs(string line){
    if (users.size() == 0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line)!=5) throw BadRequest();
    if (!thisStrExists(line,LIMIT)) throw BadRequest();
    cout << TITLE_NOTFS << endl;
    int num = 1;
    if (stoi(whatYouWant(line,LIMIT)) <= users[whoIsInSystem()]->numOfNotfs()){
        for (int i=users[whoIsInSystem()]->numOfNotfs() - 1;i >=
         users[whoIsInSystem()]->numOfNotfs() - stoi(whatYouWant(line,LIMIT));i--)
            if (!users[whoIsInSystem()]->isUnSeen(i)){
                cout << num << ". " << users[whoIsInSystem()]->showNotf(i);
                num++;
            }                        
    }
    else{
        for (int i=users[whoIsInSystem()]->numOfNotfs() - 1;i >= 0;i--)
            if (!users[whoIsInSystem()]->isUnSeen(i)){
                cout << num << ". " << users[whoIsInSystem()]->showNotf(i);
                num++; 
            }           
    }
}

int NetflixSystem::whoIsAdmin(){
    string str=ADMIN;
    HashMd5 hash;
    hash.update(str.begin(),str.end());
    hash.hex_digest(str);
    for (int i=0;i<users.size();i++)
        if (users[i]->showUserName() == ADMIN && users[i]->showPassword() == ADMIN)
            return i;
}

void NetflixSystem::BuyFilm(string line){
    if (users.size() == 0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line)!=4) throw BadRequest();
    if (!thisStrExists(line,FILM_ID)) throw BadRequest();
    if (stoi(whatYouWant(line,FILM_ID)) > numOfAllFilms ||
     thisFilmIDGotDeleted(stoi(whatYouWant(line,FILM_ID)))) throw NotFound();
    if (users[whoIsInSystem()]->showMoney() < showPriceOfThisFilm(stoi(whatYouWant(line,FILM_ID))))
        throw PermissionDenied();
    int checkHasBought = 0;
    for (int i=0;i<users[whoIsInSystem()]->numOfBoughtFilms();i++)
        if (users[whoIsInSystem()]->showFilmBoughtId(i) == stoi(whatYouWant(line,FILM_ID)))
            checkHasBought = 1;
            if (checkHasBought == 0){
                users[WHO_IS_ADMIN]->addAmountMoney(showPriceOfThisFilm(stoi(whatYouWant(line,FILM_ID))));  
                users[whoIsInSystem()]->costMoney(showPriceOfThisFilm(stoi(whatYouWant(line,FILM_ID))));
                users[whoIsInSystem()]->addBuyListFilms
                 (showPublisherOfThisFilm(stoi(whatYouWant(line,FILM_ID))),
                 showMovieNameOfThisFilm(stoi(whatYouWant(line,FILM_ID))),
                  showSummaryOfThisFilm(stoi(whatYouWant(line,FILM_ID))),
                 showDirectorOfThisFilm(stoi(whatYouWant(line,FILM_ID))),
                  showYearOfThisFilm(stoi(whatYouWant(line,FILM_ID))),
                 showLengthOfThisFilm(stoi(whatYouWant(line,FILM_ID))),
                  showPriceOfThisFilm(stoi(whatYouWant(line,FILM_ID))),
                 stoi(whatYouWant(line,FILM_ID)),users[whoIsInSystem()]->showUserID());
                users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]->PushBackNotf("User " + 
                users[whoIsInSystem()]->showUserName() +" with id " + 
                 to_string(users[whoIsInSystem()]->showUserID()) + " buy your film " + 
                  showMovieNameOfThisFilm(stoi(whatYouWant(line,FILM_ID))) + " with id "
                   + whatYouWant(line,FILM_ID) + ".\n");
    }
    cout << OK << endl;
}

void NetflixSystem::commentOnFilm(string line){
    if (users.size() == 0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line) != 6) throw BadRequest();
    if (!thisStrExists(line,FILM_ID)) throw BadRequest();
    if (stoi(whatYouWant(line,FILM_ID)) > numOfAllFilms ||
      thisFilmIDGotDeleted(stoi(whatYouWant(line,FILM_ID))) ||
        stoi(whatYouWant(line,FILM_ID)) < 0) throw NotFound();
    if (!forRateOrCmThisFilmHasBougth(whoIsInSystem(),
     stoi(whatYouWant(line,FILM_ID)))) throw PermissionDenied();
    string str = "User " + users[whoIsInSystem()]->showUserName() + 
        " with id " + to_string(users[whoIsInSystem()]->showUserID()) +
         " comment on your film " + 
        (users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]->
        showNameFilmwithFilmId(stoi(whatYouWant(line,FILM_ID)))) + " with id "
         + whatYouWant(line,FILM_ID) + ".\n";
    users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]->PushBackNotf(str);

    users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]->pushBackComment(numOfAllComments + 1,
        showMovieNameOfThisFilm(stoi(whatYouWant(line,FILM_ID))),stoi(whatYouWant(line,FILM_ID)),
        whatYouWant(line,CONTENT),whoIsInSystem(),
        users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
         ->WhichFilmHasThisID(stoi(whatYouWant(line,FILM_ID))));
    numOfAllComments++;  
    cout << OK << endl; 
}

void NetflixSystem::DeleteComment(string line){
    if (users.size() == 0 || noOneIsInSystem()) throw PermissionDenied();
    if (!isPublisher(whoIsInSystem())) throw PermissionDenied();
    if (howManySpace(line) != 6) throw BadRequest();
    if (!thisStrExists(line,COMMENT_ID)) throw BadRequest();
    if (stoi(whatYouWant(line,FILM_ID)) > numOfAllFilms || stoi(whatYouWant(line,FILM_ID)) <= 0)
        throw NotFound();
    if (stoi(whatYouWant(line,COMMENT_ID)) > numOfAllComments || stoi(whatYouWant(line,COMMENT_ID)) <= 0)
        throw NotFound();
    if (showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID))) != whoIsInSystem())
        throw PermissionDenied();
    if (!thisCmIsAvailble(stoi(whatYouWant(line,FILM_ID)),
     stoi(whatYouWant(line,COMMENT_ID)))) throw NotFound();
    if (!users[whoIsInSystem()]->thisUserHasThisCmId(stoi(whatYouWant(line,COMMENT_ID)),
        stoi(whatYouWant(line,FILM_ID)))) throw PermissionDenied();
    users[whoIsInSystem()]->setUnavailbleThisComment(stoi(whatYouWant(line,COMMENT_ID)),
     stoi(whatYouWant(line,FILM_ID)));
    cout << OK << endl;   
}

void NetflixSystem::replyOnComment(string line){
    if (users.size() == 0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line) != 8) throw BadRequest();
    if (!thisStrExists(line,FILM_ID) || !thisStrExists(line,COMMENT_ID) ||
     !thisStrExists(line,CONTENT)) throw BadRequest();
    if (!isPublisher(whoIsInSystem())) throw PermissionDenied();
    if (stoi(whatYouWant(line,FILM_ID)) > numOfAllFilms ||
     stoi(whatYouWant(line,FILM_ID)) < 0) throw NotFound();
    if (stoi(whatYouWant(line,COMMENT_ID)) > numOfAllComments) throw NotFound();
    if (!thisCmIsAvailble(stoi(whatYouWant(line,FILM_ID)),
     stoi(whatYouWant(line,COMMENT_ID)))) throw NotFound();
    if (showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))
     != whoIsInSystem()) throw PermissionDenied();
    if (!users[whoIsInSystem()]->thisUserHasThisCmId(stoi(whatYouWant(line,COMMENT_ID)),
        stoi(whatYouWant(line,FILM_ID)))) throw PermissionDenied();
    if (!thisFilmHastThisCmId(stoi(whatYouWant(line,FILM_ID)),
    stoi(whatYouWant(line,COMMENT_ID)),whoIsInSystem())) throw NotFound();
    users[whoIsInSystem()]->PushBackReplyCmMessage(whatYouWant(line,CONTENT),
    stoi(whatYouWant(line,FILM_ID)),stoi(whatYouWant(line,COMMENT_ID)));
    users[showWhichUserHasCommentorID(stoi(whatYouWant(line,COMMENT_ID)),whoIsInSystem())]->PushBackNotf(
        "Publisher " + users[whoIsInSystem()]->showUserName() + " with id " +
         to_string(users[whoIsInSystem()]->showUserID()) + " reply to your comment.\n"
    );
    cout << OK << endl;
}


void NetflixSystem::rateOnFilm(string line){
    if (users.size() ==0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line) != 6 ) throw BadRequest();
    if (!thisStrExists(line,FILM_ID)) throw BadRequest();
    if (thisFilmIDGotDeleted(stoi(whatYouWant(line,FILM_ID))) ||
     stoi(whatYouWant(line,FILM_ID)) > numOfAllFilms || 
        stoi(whatYouWant(line,FILM_ID)) <=0) throw NotFound();
    if (!forRateOrCmThisFilmHasBougth(whoIsInSystem(),stoi(whatYouWant(line,FILM_ID))))
        throw PermissionDenied(); 
    if (stof(whatYouWant(line,SCORE)) > 10 || stof(whatYouWant(line,SCORE)) < 0) throw BadRequest();
    users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]->
     addRateToMovie(stoi(whatYouWant(line,FILM_ID)),stof(whatYouWant(line,SCORE)),
      users[whoIsInSystem()]->showUserID());
    users[whoIsInSystem()]->addRateToMovie(stoi(whatYouWant(line,FILM_ID)),
    stof(whatYouWant(line,SCORE)),users[whoIsInSystem()]->showUserID());
    users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]->PushBackNotf("User " +
     users[whoIsInSystem()]->showUserName() + " with id " +
        to_string(users[whoIsInSystem()]->showUserID()) + " rate your film " +
         users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]->
        showNameFilmwithFilmId(stoi(whatYouWant(line,FILM_ID))) + " with id " +
         whatYouWant(line,FILM_ID) + ".\n");
    cout << OK << endl;
}

void NetflixSystem::addSalaryAdmin(int filmID, int whichFilm){
    if (users[showWhichUserWithFilmId(filmID)]->thisFilmIsStrong(whichFilm))
        users[WHO_IS_ADMIN]->addAmountMoney(0.05 *
         users[showWhichUserWithFilmId(filmID)]->showPriceFilm(filmID));
    if (users[showWhichUserWithFilmId(filmID)]->thisFilmIsNormal(whichFilm))
        users[WHO_IS_ADMIN]->addAmountMoney(0.1 *
         users[showWhichUserWithFilmId(filmID)]->showPriceFilm(filmID));
    if (users[showWhichUserWithFilmId(filmID)]->thisFilmIsWeak(whichFilm))
        users[WHO_IS_ADMIN]->addAmountMoney(0.2 *
         users[showWhichUserWithFilmId(filmID)]->showPriceFilm(filmID));       
}

void NetflixSystem::getSalary(string line){
    if (users.size() == 0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line) != 1) throw BadRequest();
    if (!isPublisher(whoIsInSystem())) throw PermissionDenied();
    users[whoIsInSystem()]->setMoneyToZero();
    for (int published=0;published<users[whoIsInSystem()]->numOfFilms();published++)
        for (int allUser=0;allUser<users.size();allUser++)
            for (int i=0;i<users[allUser]->numOfBoughtFilms();i++)
                if (users[whoIsInSystem()]->showFilmId(published) ==
                 users[allUser]->showFilmBoughtId(i)){
                    users[whoIsInSystem()]->addSalary(published);
                    if (users[showWhichUserWithFilmId(users[whoIsInSystem()]->showFilmId(published))]
                        ->filmIsStrong(users[whoIsInSystem()]->showFilmId(published)))
                        users[WHO_IS_ADMIN]->costMoneyOfAdmin(0.95,
                        users[showWhichUserWithFilmId(users[whoIsInSystem()]->
                        showFilmId(published))]->showPriceFilm(users[whoIsInSystem()]
                        ->showFilmId(published)));
                    if (users[showWhichUserWithFilmId(users[whoIsInSystem()]->showFilmId(published))]
                        ->filmIsNormal(users[whoIsInSystem()]->showFilmId(published)))
                        users[WHO_IS_ADMIN]->costMoneyOfAdmin(0.9,
                        users[showWhichUserWithFilmId(users[whoIsInSystem()]->
                        showFilmId(published))]->showPriceFilm(users[whoIsInSystem()]
                        ->showFilmId(published)));
                    if (users[showWhichUserWithFilmId(users[whoIsInSystem()]->showFilmId(published))]
                        ->filmIsWeak(users[whoIsInSystem()]->showFilmId(published))) 
                        users[WHO_IS_ADMIN]->costMoneyOfAdmin(0.8,
                        users[showWhichUserWithFilmId(users[whoIsInSystem()]->
                        showFilmId(published))]->showPriceFilm
                        (users[whoIsInSystem()]->showFilmId(published)));
                }
    cout << OK << endl;
}

bool NetflixSystem::thisFilmHasBoughtByThisPerson(int filmID, int who){
    for (int i=0;i<users[who]->numOfBoughtFilms();i++)
        if (users[who]->showFilmBoughtId(i) == filmID)
            return true;
}

void NetflixSystem::swapTwoFilmsForRate(vector<Film*> &films,vector<int> &filmsVector,int i,int j){
    Film* tmp;
    tmp = films[i];
    films[i] = films[j];
    films[j] = tmp;
    int temp;
    temp = filmsVector[j];
    filmsVector[j] = filmsVector[i];
    filmsVector[i] = temp;
}

bool NetflixSystem::hasBoughtThisFilm(int who, int filmID){
    for (int i=0;i<users[who]->numOfBoughtFilms();i++)
        if (users[who]->showFilmBoughtId(i) == filmID)
            return true;
}

void NetflixSystem::rateBasedOnRecommendation(vector<Film*> &filmsForRecommend,
 string line, int& which){
    recommenedations.clear();
    for (int num=0;num<users.size();num++)
        if (isPublisher(num))
            for (int i=0;i<users[num]->numOfFilms();i++)
                if (users[num]->thisFilmHasntDeleted(i))
                    filmsForRecommend.push_back(users[num]->returnFilms(i));                
    for (which;which<filmsForRecommend.size();which++)
        if (filmsForRecommend[which]->ShowFilmId() == stoi(whatYouWant(line,FILM_ID)))
            break;
    for (int i=0;i<filmsForRecommend.size();i++)
        recommenedations.push_back(0);
    for (int allUsers=0;allUsers<users.size();allUsers++)
        for (int j = 0;j<filmsForRecommend.size();j++)
            if (hasBoughtThisFilm(allUsers,filmsForRecommend[which]->ShowFilmId())
             && hasBoughtThisFilm(allUsers,filmsForRecommend[j]->ShowFilmId()))
                if (which != j)
                    recommenedations[j]++;
    for (int i=0;i<filmsForRecommend.size();i++)
        for (int j=i+1;j<filmsForRecommend.size();j++)
            if (recommenedations[i] < recommenedations[j])
                swapTwoFilmsForRate(filmsForRecommend,recommenedations,i,j);
    for (int i=0;i<filmsForRecommend.size();i++)
        for (int j=i+1;j<filmsForRecommend.size();j++)
            if (recommenedations[i] == recommenedations[j]){
                if (filmsForRecommend[i]->ShowFilmId() > filmsForRecommend[j]->ShowFilmId())
                    swapTwoFilmsForRate(filmsForRecommend,recommenedations,i,j);
            }            
}

void NetflixSystem::showDetailsOfFilm(string line){
    if (users.size() == 0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line) != 4 ) throw BadRequest();
    if (!users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]->
     thisFilmIdExists(stoi(whatYouWant(line,FILM_ID)))) throw NotFound();
    if (stoi(whatYouWant(line,FILM_ID)) > numOfAllFilms ||
      stoi(whatYouWant(line,FILM_ID)) < 0) throw NotFound();
    if (thisFilmIDGotDeleted(stoi(whatYouWant(line,FILM_ID)))) throw NotFound();
    cout << "Details of Film " <<  users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
        ->showNameFilmwithFilmId(stoi(whatYouWant(line,FILM_ID))) << endl << "Id = " <<
         stoi(whatYouWant(line,FILM_ID)) << endl << 
         "Director = " << users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
          ->showDirectorWithFilmId(stoi(whatYouWant(line,FILM_ID))) << endl <<
           "Length = " << users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
            ->showLengthWithFilmId(stoi(whatYouWant(line,FILM_ID))) << endl <<
             "Year = " << users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
              ->showYearWithFilmId(stoi(whatYouWant(line,FILM_ID))) << endl << 
             "Summary = " << users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
              ->showSummaryWithFilmId(stoi(whatYouWant(line,FILM_ID))) << endl <<
              "Rate = " << users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
               ->showRateWithFilmId(stoi(whatYouWant(line,FILM_ID))) << endl <<
                "Price = " << users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
                 ->showPriceFilm(stoi(whatYouWant(line,FILM_ID))) << endl << endl <<
                  "Comments" << endl;
    for (int i=0;i<users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]->
     numOfCommentsOfThisFilmId(stoi(whatYouWant(line,FILM_ID)));i++){
        if (users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
         ->thisCmAvailble(stoi(whatYouWant(line,FILM_ID))
         ,users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
          ->showCmId(i,stoi(whatYouWant(line,FILM_ID))))){
        cout << users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
         ->showCmId(i,stoi(whatYouWant(line,FILM_ID)))
            << ". " <<users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
             ->showCm(i,0,stoi(whatYouWant(line,FILM_ID))) << endl;
        if (users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]->
        numOfMsgsOfThisFilmId(stoi(whatYouWant(line,FILM_ID)),i) > 1)
            for (int j=1;j<users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
            ->numOfMsgsOfThisFilmId(stoi(whatYouWant(line,FILM_ID)),i);j++){
                cout << users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
                ->showCmId(i,stoi(whatYouWant(line,FILM_ID))) << "." << j << ". " <<
                    users[showWhichUserWithFilmId(stoi(whatYouWant(line,FILM_ID)))]
                     ->showCm(i,j,stoi(whatYouWant(line,FILM_ID))) << endl;
            }
        }
    }
    cout << endl << "Recommendation Film" << endl <<
      "#. Film Id | Film Name | Film Length | Film Director" << endl;
    vector<Film*> filmsForRankRate;
    int which = 0;
    rateBasedOnRecommendation(filmsForRankRate,line,which);
    for (int i=0;i<filmsForRankRate.size();i++)
        for (int j=0;j<filmsForRankRate[i]->numOfBuyer();j++)                
            if (filmsForRankRate[i]->ShowFilmId() == users[whoIsInSystem()]->showFilmBoughtId(j)){
                filmsForRankRate.erase(filmsForRankRate.begin() + i);
                i--;
            }
    if (filmsForRankRate.size() > 4)
        for (int i=0;i<4;i++)
            cout << i+1 << ". " << filmsForRankRate[i]->ShowFilmId() << " | " <<
              filmsForRankRate[i]->showName() <<
             " | " << filmsForRankRate[i]->showLength()
             << " | " << filmsForRankRate[i]->showDirector() << endl;
    else 
        for (int i=0;i<filmsForRankRate.size();i++)
            cout << i+1 << ". " << filmsForRankRate[i]->ShowFilmId() << " | " <<
              filmsForRankRate[i]->showName() <<
             " | " << filmsForRankRate[i]->showLength()
              << " | " << filmsForRankRate[i]->showDirector() << endl;
    filmsForRankRate.clear();
}

void NetflixSystem::filterPurchasedFilms(string line){
    if (users.size() == 0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line) < 1 || howManySpace(line) > 14) throw BadRequest();
    vector<Film*> filmsPurchasedFilter;
    for (int i=0;i<users[whoIsInSystem()]->numOfBoughtFilms();i++){
        filmsPurchasedFilter.push_back(users[whoIsInSystem()]->returnFilmsPurchased(i));
    }
    if (thisStrExists(line,NAME))
        for (int i=0;i<filmsPurchasedFilter.size();i++){
            if (filmsPurchasedFilter[i]->showName() != whatYouWant(line,NAME)){
                filmsPurchasedFilter.erase(filmsPurchasedFilter.begin() + i);
                i--;
            }
        }
    if (thisStrExists(line,PRICE))
        for (int i=0;i<filmsPurchasedFilter.size();i++)
            if (filmsPurchasedFilter[i]->showPrice() != stoi(whatYouWant(line,PRICE))){
                filmsPurchasedFilter.erase(filmsPurchasedFilter.begin() + i);
                i--;
            }
    if (thisStrExists(line,DIRECTOR))
        for (int i=0;i<filmsPurchasedFilter.size();i++)
            if (filmsPurchasedFilter[i]->showDirector() != whatYouWant(line,DIRECTOR)){
                filmsPurchasedFilter.erase(filmsPurchasedFilter.begin() + i);
                i--;
            }
    if (thisStrExists(line,MAX_YEAR))
        for (int i=0;i<filmsPurchasedFilter.size();i++)
            if (filmsPurchasedFilter[i]->showYear() > stoi(whatYouWant(line,MAX_YEAR))){
                filmsPurchasedFilter.erase(filmsPurchasedFilter.begin() + i);
                i--;
            }
    if (thisStrExists(line,MIN_YEAR))
        for (int i=0;i<filmsPurchasedFilter.size();i++)
            if (filmsPurchasedFilter[i]->showYear() < stoi(whatYouWant(line,MIN_YEAR))){
                filmsPurchasedFilter.erase(filmsPurchasedFilter.begin() + i);
                i--;
            }
    if (thisStrExists(line,MIN_RATE))
        for (int i=0;i<filmsPurchasedFilter.size();i++)
            if (filmsPurchasedFilter[i]->showRate() < stof(whatYouWant(line,MIN_RATE))){
                filmsPurchasedFilter.erase(filmsPurchasedFilter.begin() + i);
                i--;
            }
    for (int i=0;i<filmsPurchasedFilter.size();i++)
        if (!filmsPurchasedFilter[i]->IsAvailble()){
            filmsPurchasedFilter.erase(filmsPurchasedFilter.begin() + i);
            i--;
        }
    cout << TITLE_FILTER_PUBLISHED << endl;
    for (int i=0;i<filmsPurchasedFilter.size();i++)
        cout <<  i+1 << ". " << filmsPurchasedFilter[i]->ShowFilmId() << " | " <<
          filmsPurchasedFilter[i]->showName()
            << " | " << filmsPurchasedFilter[i]->showLength() << " | " <<
              filmsPurchasedFilter[i]->showPrice() << " | "
             << filmsPurchasedFilter[i]->showRate()
              << " | " << filmsPurchasedFilter[i]->showYear() << " | " <<
                filmsPurchasedFilter[i]->showDirector() << endl;
    filmsPurchasedFilter.clear();                 
}


void NetflixSystem::showMoneyOfThisUser(string line){
    if (users.size() == 0 || noOneIsInSystem()) throw PermissionDenied();
    if (howManySpace(line) != 1) throw BadRequest();
    string str = ADMIN;
    HashMd5 hash;
    hash.update(str.begin(),str.end());
    hash.hex_digest(str);
    if (users[whoIsInSystem()]->showUserName() == ADMIN && users[whoIsInSystem()]->showPassword() == ADMIN)
        cout << users[WHO_IS_ADMIN]->showMoney() << endl;
    else
        cout << users[whoIsInSystem()]->showMoney() << endl;
}

void NetflixSystem::run(string line){
    try{
        if (line.length() != 0){
            int tst = 0;
            if (!isTwoCommands(line)) throw BadRequest();
            if (thisStrExists(line,QUESTION)){
                if (firstString(line) == POST && whatYouWant(line,POST) == SIGNUP &&
                 whatYouWant(line,SIGNUP) == QUESTION){
                    signUp(line);
                    tst = 1;
                }
                if (firstString(line) == POST && whatYouWant(line,POST) == LOGIN &&
                 whatYouWant(line,LOGIN) == QUESTION){
                    Login(line);
                    tst = 1;
                }
                if (firstString(line) == POST && whatYouWant(line,POST) == FILMS &&
                 whatYouWant(line,FILMS) == QUESTION){
                    PostFilm(line);
                    tst = 1;
                }
                if (firstString(line) == POST && whatYouWant(line,POST) == PUT_FILMS &&
                 whatYouWant(line,FILMS) == QUESTION){
                    EditFilm(line);
                    tst = 1;
                }
                if (firstString(line) == POST && whatYouWant(line,POST) == DELETE_FILMS &&
                 whatYouWant(line,FILMS) == QUESTION){
                    deleteFilmid(line);   
                    tst = 1;
                }
                if (firstString(line) == GET && whatYouWant(line,GET) == PUBLISHED &&
                 whatYouWant(line,PUBLISHED) == QUESTION){
                    filterFilmsPublished(line);
                    tst = 1;
                }
                if (firstString(line) == POST && whatYouWant(line,POST) == MONEY &&
                 whatYouWant(line,MONEY) == QUESTION && howManySpace(line) == 4){
                    addMoney(line);
                    tst = 1;
                }
                if (firstString(line) == POST && whatYouWant(line,POST) == FOLLOWERS &&
                 whatYouWant(line,FOLLOWERS) == QUESTION){
                    FollowPublisher(line); 
                    tst = 1;
                }
                if (firstString(line) == POST && whatYouWant(line,POST) == BUY &&
                 whatYouWant(line,BUY) == QUESTION){
                    BuyFilm(line);
                    tst = 1;
                }
                if (firstString(line) == GET && whatYouWant(line,GET) == NOTIFICATIONS &&
                 howManySpace(line)>1 &&
                whatYouWant(line,NOTIFICATIONS) == READ && whatYouWant(line,READ) == QUESTION){
                    showSeenNotfs(line);
                    tst = 1;
                }
                if (firstString(line) == POST && whatYouWant(line,POST) == COMMENT &&
                 whatYouWant(line,COMMENT) == QUESTION){
                    commentOnFilm(line);
                    tst = 1;
                }
                if (firstString(line) == POST && whatYouWant(line,POST) == REPLIES &&
                 whatYouWant(line,REPLIES) == QUESTION){
                    replyOnComment(line);
                    tst = 1;
                }
                if (firstString(line) == POST && whatYouWant(line,POST) == DELETE_CMS &&
                 whatYouWant(line,COMMENT) == QUESTION){
                    DeleteComment(line);
                    tst = 1;
                }
                if (firstString(line) == POST && whatYouWant(line,POST) == RATE &&
                 whatYouWant(line,RATE) == QUESTION){
                    rateOnFilm(line);
                    tst = 1;
                }
                if (firstString(line) == GET && whatYouWant(line,GET) == FILMS &&
                 whatYouWant(line,FILMS) == QUESTION &&
                 !thisStrExists(line,FILM_ID)){
                    filterAllFilms(line);
                    tst = 1;
                }
                if (firstString(line) == GET && whatYouWant(line,GET) == FILMS &&
                 whatYouWant(line,FILMS) == QUESTION &&
                 thisStrExists(line,FILM_ID)){
                    showDetailsOfFilm(line);
                    tst = 1;
                }
                if (firstString(line) == GET && whatYouWant(line,GET) == PURCHASED &&
                 whatYouWant(line,PURCHASED) == QUESTION){
                    filterPurchasedFilms(line);
                    tst = 1;
                }
            }
            if (!thisStrExists(line,QUESTION)){
                if (firstString(line) == GET && whatYouWant(line,GET) == MONEY){
                    showMoneyOfThisUser(line);
                    tst = 1;
                }
                if (firstString(line) == GET && whatYouWant(line,GET) == FOLLOWERS){
                    showFollowers(line);
                    tst = 1;
                }
                if (firstString(line) == GET && whatYouWant(line,GET) == FILMS){
                    filterAllFilms(line);
                    tst = 1;
                }
                if (firstString(line) == GET && whatYouWant(line,GET) == PUBLISHED){
                    filterFilmsPublished(line);
                    tst = 1;
                }
                if (firstString(line) == POST && whatYouWant(line,POST) == MONEY &&
                 howManySpace(line) == 1){
                    getSalary(line);
                    tst = 1;
                }
                if (firstString(line) == GET && whatYouWant(line,GET) == NOTIFICATIONS &&
                 howManySpace(line) ==1){ 
                    showUnseenNotfs(line);
                    tst = 1;
                }
                if (firstString(line) == GET && whatYouWant(line,GET) == PURCHASED){
                    filterPurchasedFilms(line);
                    tst = 1;
                }
                if (firstString(line) == POST && whatYouWant(line,POST) == LOGOUT){
                    logOut(line);
                    tst = 1;
                }
            }
            if (tst == 0) throw NotFound();
        }
    }catch(exception& e){ cout << e.what(); }
}