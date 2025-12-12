#include "Placement.h"

Placement::Placement(string name, string description)
    : Module(name, 0, 15), _description(description) {}

string Placement::getDescription() const { return _description; }
void Placement::setDescription(string d) { _description = d; }
