#include <iostream>
#include <string>
#include <vector>
#include "netflix.h"
#include "defines.h"

using namespace std;
int main(){
    string line;
    NetflixSystem* netFlix = new NetflixSystem(EMAIL_ADMIN,ADMIN,ADMIN,19,1,0);
    while(getline(cin,line))  netFlix->run(line);
    delete netFlix;
}