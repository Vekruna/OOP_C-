#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

class VIDEO {
private:
    string Name;
    int Year;
    string Genre;
    string Rezhiser;

public:
    VIDEO(); 
    void input();  
    void output() const;

    string getRezhiser() const; 
};

#endif
