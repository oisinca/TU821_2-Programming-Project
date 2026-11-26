// placeManager class stores and manages all locations 
//and allows locations to be retrieved
#pragma once

#include "Place.h"
#include "narrative.h"
using namespace std;

class PlaceManager
{
private:
    
    Place places[5]; // creates an array of 5 place objects. each object represents one game location

public:
    PlaceManager(); // default constructor

    ~PlaceManager(); //  destructor

    // functions
    void createPlaces(); // creates all 5 locations with their names and desc
    Place getPlace(int index); // retrieves a particular location from the array
    
};
