#ifndef MODULE_H
#define MODULE_H

#include <string>
using namespace std;

class Module {
protected:
    string _name;
    unsigned int _students;
    unsigned int _credits;

public:
    Module(string name = "", unsigned int students = 0, unsigned int credits = 2);

    string getName() const;
    unsigned int getStudents() const;
    unsigned int getCredits() const;

    void setName(string);
    void setStudents(unsigned int);
    void setCredits(unsigned int);

    bool operator==(const Module& other) const;
};

#endif
