// Place.h defines what and indivual location containes
#pragma once

#include <iostream>
#include <string>
using namespace std;
// other headers that are needed;
// #include "Enemy.h"
// #include "Loot.h"
// #include "Armour.h"

class Place
{
private:
    string PlaceName;
    string PlaceDescription;

public:
    Place();
    Place(string name, string desc);

    ~Place();

    // functions
    void displayPlace();
    
    string getPlacename();

    void PlaceStory();

};




// #pragma once (old place class)

// #include <iostream>
// #include <string>
// using namespace std;
// // other headers that are needed;
// //#include "Enemy.h"
// // #include "Loot.h"
// // #include "Armour.h"

// class Place
// {
// private:
//     void home();
//     void bar();
//     void church();
//     void shticks();
//     void cave();

//     void area(string placeName);

// public:
//     Place();
//     ~Place();
    

//     Place(string home, string bar, string church, string cave);
    
    
    
// };


// class places
// Home:                Home:               Home:
// O takes : revolver   D take : Sg             jack: nothing
// i go to bar          he goes to Church           Shootout, dies!
// i quit and save the game.    kill guys, get new gun      ragequit.
                                // save and quit;            Home;


// spawn back in the bar;

// kill badguys drink ass;
//

//PLACE{
// nameOfPlace;
// enemysInPlace;
// Story; -> get file (places)-> places[home, bar, church, theShticks] 
// 
// lootAvailableToObtain;
// miniGamesInPlace;
//};