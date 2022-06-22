#include <iostream>
#include <string>

class BadRequest : public std::exception{
    virtual const char* what() const throw(){
        return "Bad Request\n";
    }
};

class PermissionDenied : public std::exception{
    virtual const char* what() const throw(){
        return "Permission Denied\n";
    }
};

class NotFound : public std::exception{
    virtual const char* what() const throw(){
        return "Not Found\n";
    }
};