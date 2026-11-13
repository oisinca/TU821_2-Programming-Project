#include <windows.h>
#include <iostream>

#include "game.h"

// For delay: sleep(time_in_milli);

//Main Function
int main(){
    srand(time(0));
    Game game;  //initialize game object
    game.Run(); //begin game loop (go to game.cpp to see the game loop)
return 0;
}
