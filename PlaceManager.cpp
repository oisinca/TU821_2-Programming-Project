#include "PlaceManager.h"

PlaceManager::PlaceManager()
{
}

PlaceManager::~PlaceManager()
{
}
// Places place[5] = {home, bar, church, shticks, cave};
// FILESYO(place[5])
// FILESload(places[0])
// if (fliesload(places[0]))
//  {
//       DO HOME STUFF
//  }

// assigns a location to each position in the array
void PlaceManager::createPlaces()
{
    places[0] = Place("Home", "The hunt begins");
    places[1] = Place("The Bar", "A local tavern");
    places[2] = Place("The Shticks", "The outback");
    places[3] = Place("The Church", "An old church");
    places[4] = Place("The Cave", "Paul's residence");
    //If using the pointer this will have to change also i believe
    //I think it has to be a pointer because its gonna change the value of something in Place class
    //dont quote me tho, id google (claude) it. 
}

// returns the place object at the requested index
Place PlaceManager::getPlace(int index)
{
    return places[index];
}
