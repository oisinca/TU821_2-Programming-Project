// Place.h defines what and indivual location containes
// stores the location's names and descriptions
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
    string PlaceName;  // stores name of the location
    string PlaceDescription; // stores the description of place


public:
    Place(); // default constructor
    Place(string name, string desc); // overloaded constructor:initialises name and description of place
    ~Place(); // destructor

    // functions
    void displayPlace(); // function to display place's name and description
    
    string getPlacename(); // returns place name
    string getPLaceDescription(); // returns place description

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