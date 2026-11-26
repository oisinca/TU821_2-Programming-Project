#include "narrative.h"
#include "Place.h"

Place::Place()
{
    PlaceName = "N/A";
    PlaceDescription = "N/A";
}

Place::Place(string name, string desc)
{
    PlaceName = name;
    PlaceDescription = desc;
}

void Place::displayPlace() // displays name and desc
{
    cout << "You have entered: " << PlaceName << endl;
    cout << PlaceDescription << endl;
}

string Place::getPlacename() // returns place name
{
    return PlaceName;
}

string Place::getPLaceDescription() // returns place desc
{
    return PlaceDescription;
}

Place::~Place()
{
}
