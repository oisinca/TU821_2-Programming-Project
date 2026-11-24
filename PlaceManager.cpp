#include "PlaceManager.h"

PlaceManager::PlaceManager()
{
    for(int i = 0; i < 5; i++)
    {
        places[i] = nullptr;
    }
}

PlaceManager::~PlaceManager()
{
      for(int i = 0; i < 5; i++)
    {
        delete places[i];
    }
}
//Places place[5] = {home, bar, church, shticks, cave};
//FILESYO(place[5])
//FILESload(places[0])
//if (fliesload(places[0]))
// {
//      DO HOME STUFF
// }
void PlaceManager::Home()
{
    places[0] = new Place("Home", " A warmly lit room");
}

void PlaceManager::Bar()
{
    places[1] = new Place("Bar", "A rowdy tavern");

}

void PlaceManager::Church()
{
    places[2] = new Place("Church", "A holy building");
}

void PlaceManager::theShticks()
{
    places[3] = new Place("TheShticks", "The scortching outback");
}

void PlaceManager::Cave()
{
    places[4] = new Place("The Cave", "Paul's residence");
}

void PlaceManager::createPlaces()
{
}
