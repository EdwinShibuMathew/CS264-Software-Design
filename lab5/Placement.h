#ifndef PLACEMENT_H
#define PLACEMENT_H

#include "Module.h"

class Placement : public Module {
private:
    string _description;

public:
    Placement(string name = "Placement", string description = "");
    
    string getDescription() const;
    void setDescription(string);
};

#endif
