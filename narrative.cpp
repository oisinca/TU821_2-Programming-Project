#include <iostream>

#include "game.h"
#include "narrative.h"
using namespace std;
Narrative::Narrative()
{

}

Narrative::~Narrative()
{

}

void Narrative::intro() //intro sequence of the game, this is the first part of the game
{
    void starter_chest_open();
    char choice; 
    //must add input checking to make sure the user inputs a valid option, if not it will ask them to try again.
    cout << "You wake up....";
    cont_clr();
    cout << "It's scortching hot outside";
    cont_clr();
    cout << "That was a weird dream"; 
    //this will lead on to the fact they have gear left on the dresser from previus run
    cont_clr();
    
    /*
     make sure to add the if: 
     if(had gear and died){cout << "There seems to be a(n) " << ...
     ITEM_FROM_DEATH << " on the dresser \n I wonder why?" << endl
     update inventory to hold item}
    */
     
    
    do{
        cout << "You stand up and walk over to your storage chest...\n";
        cout << "Would you like to open it, or exit through the front door?\n";
        cout << "Open (O)\nExit(E)\n"; //First dialogue option
        cin >> choice;

        choice = tolower(choice);  
        if (choice != 'o' && choice != 'e')
            {
                cerr << "Invalid input please try again\n";
                cont_clr();
            } //if the user inputs anything other than 'o' or 'e', it will display an error message 
              //and ask them to try again
            

    }while(choice != 'o' && choice != 'e'); //while loop will keep asking the user for input until they enter a valid option

    if(choice == 'o')
    {
        Loot loot("Ch1"); // chest 1 (starter chest) 
    }
    else if (choice == 'e')
    {
        cout << "You have exited through the front door\n";
         // this skips the chest squence and goes straight outside with no gear.
        cont_clr();
    }

    outside_house();
}

void Narrative::outside_house()
{   
    char choice;
    cout << "You have exited the house and are now in the desert\n";
    cont_clr();
    cout << "You see a small town in the distance, you walk towards it\n";
    cont_clr();
    cout << "The air is dry and hot, you can feel the sweat dripping down your face\n";
    cont_clr();
    cout << "You hear a gunshot in the distance, you look around and see a small group of people running towards you\n\n";
    cout << "DIALOGUE OPTION:\n";
    cout << "Would you like to ask them what's going on, or run away?\n";
    cout << "Ask (a)\nRun (r)\n";
    //dialogue was changed from this to being done in functions below, its much cleaner i advise you do the same
    cin >> choice;
    choice = tolower(choice);
    //must add input checking to make sure the user inputs a valid option, if not it will ask them to try again.
    switch (choice)
    {
        case 'a':
            system("cls");
            dialogueOneA();
            break;
        case 'r':
            system("cls");
            cout << "You have chosen to run away\n";
            cont_clr();    
            //Doill or Jack you can maybe add your sequences here
            break;
    }
    
    cout << "You have entered the town, and see the big red wooden building the cowboy was talking about\n";
    cont_clr();
    cout << "You can smell the gunpowder in the air, and see smoke rising from behind the bar.\n";
    cont_clr();
    cout << "You can hear the sound of gunfire and shouting coming from inside the bar.\n";
    cont_clr();
    cout << "You look to your right and see the sheriff's station.";
    cont_clr();
    dialogueTwoA();
}

void Narrative::cont_clr()
{
    cout << "\n\n";
    system("pause");
    system("cls");
}

void Narrative::dialogueOneA()
{
    char choice;
    system("cls");
    cout << "'Theres been a shootout in the bar.' - Passing Cowboy\n\n";
    cout << "DIALOGUE OPTION:\n";
    cout << "'Why was there a shootout?' (w)\n";
    cout << "'Where is the bar?' (b)\n";
    cin >> choice;
    choice = tolower(choice);
    //must add input checking to make sure the user inputs a valid option, if not it will ask them to try again.
    switch (choice)
    {
        case 'w':
            system("cls");
            cout << "'I don't know. \nTheres always shootouts at the bar' - Passing Cowboy\n";
            system("pause");
            minidialogue();
            break;
        case 'b':
            system("cls");
            cout << "'Its the big red wooden building in the middle of town'\n'You can't miss it' - Passing Cowboy\n\n";
            cont_clr();
            cout << "'I guess I should go check it out' - You\n";
            cont_clr();
            break;
    }
}
void Narrative::minidialogue()
{
    char choice;
    cout << "DIALOGUE OPTION:\n";
    cout << "'Where is the bar?' (b)\n";
    cout << " 'Run away' (r)\n";
    cin >> choice;
    choice = tolower(choice);
    //must add input checking to make sure the user inputs a valid option, if not it will ask them to try again.
    switch (choice)
    {
        case 'b':
            system("cls");
            cout << "'Its the big red wooden building in the middle of town'\n'You can't miss it' - Passing Cowboy\n";
            system("pause");
            cout << "'I guess I should go check it out' - You\n";
            cont_clr();
            break;
        case 'r':
            system("cls");
            cout << "You have chosen to run away\n";
            cont_clr();    
            //Doill or Jack you can maybe add your sequences here
            ranAway();
            break;
    }
}

void Narrative::dialogueTwoA()
{
    char choice;
    cout << "Path Option:\n(A)Go to the bar\n(B)Go inside the Sheriff's office and ask why they arent doing anything\n";
    cin >> choice;
    choice = tolower(choice);
    //must add input checking to make sure the user inputs a valid option, if not it will ask them to try again.
    switch (choice)
    {
        case 'a':
            system("cls");
            cout << "You have chosen to go to the bar\n";
            cont_clr();
            //Bar sequence here
            break;
        case 'b':
            system("cls");
            cout << "You have chosen to go to the sheriff's office\n"; 
            //doesnt have to be sherriffs, could be whatever you want it to be, just make sure to change the text in the cout statement above
            cont_clr();
            //Sheriff's office sequence here
            break;
    }
}

void Narrative::ranAway()
{
    cout << "You flee into the crowd and disappear before the cowboy can catch up.\n";
    cont_clr();
}
