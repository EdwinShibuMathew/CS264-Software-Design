#include "Module.h"

Module::Module(string name, unsigned int students, unsigned int credits)
    : _name(name), _students(students), _credits(credits) {}

string Module::getName() const { return _name; }
unsigned int Module::getStudents() const { return _students; }
unsigned int Module::getCredits() const { return _credits; }

void Module::setName(string n) { _name = n; }
void Module::setStudents(unsigned int s) { _students = s; }
void Module::setCredits(unsigned int c) { _credits = c; }

bool Module::operator==(const Module& other) const {
    return (_name == other._name && _credits == other._credits);
}
