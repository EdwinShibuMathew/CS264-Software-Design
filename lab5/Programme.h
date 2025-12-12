#ifndef PROGRAMME_H
#define PROGRAMME_H

#include <string>
#include <sstream>
#include "Module.h"

class Programme {
private:
    string _name;
    unsigned int _year;
    unsigned int _capacity;
    unsigned int _count;
    Module *modules;   // dynamic array

public:
    Programme(string name, unsigned int year, unsigned int capacity);
    ~Programme();

    string getName() const;
    unsigned int getYear() const;

    void setName(string);
    void setYear(unsigned int);

    bool addModule(const Module& m);

    string toStr() const;
};

#endif
