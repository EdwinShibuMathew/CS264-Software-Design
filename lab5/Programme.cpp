#include "Programme.h"

Programme::Programme(string name, unsigned int year, unsigned int capacity)
    : _name(name), _year(year), _capacity(capacity), _count(0) 
{
    modules = new Module[_capacity];
}

Programme::~Programme() {
    delete[] modules;
}

string Programme::getName() const { return _name; }
unsigned int Programme::getYear() const { return _year; }

void Programme::setName(string n) { _name = n; }
void Programme::setYear(unsigned int y) { _year = y; }

bool Programme::addModule(const Module& m) {
    if (_count >= _capacity) return false;
    modules[_count++] = m;
    return true;
}

string Programme::toStr() const {
    stringstream ss;
    ss << "Programme: " << _name << " (Year " << _year << ")\n";

    for (unsigned int i = 0; i < _count; i++) {
        ss << "- " << modules[i].getName()
           << " | Credits: " << modules[i].getCredits()
           << " | Students: " << modules[i].getStudents()
           << "\n";
    }
    return ss.str();
}
