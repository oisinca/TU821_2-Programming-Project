// placeManager defines how all the locations are stored and accessed
#pragma once

#include "Place.h"

using namespace std;

class PlaceManager
{
private:
   
    Place *places[5];

    // individual area creation functions
    void Home();
    void Bar();
    void Church();
    void theShticks();
    void Cave();

public:
    PlaceManager();

    ~PlaceManager();

    // functions
    void createPlaces();
    
};
