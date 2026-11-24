#include "narrative.h"
#include "Place.h"

Place::Place()
{
}

Place::Place(string name, string desc)
{
    PlaceName = name;
    PlaceDescription = desc;
}

Place::~Place()
{
}

void Place::displayPlace()
{
    cout << "You have entered " << PlaceName << endl;
}

string Place::getPlacename()
{
    return PlaceName;
}

void Place::PlaceStory()
{
    
}
