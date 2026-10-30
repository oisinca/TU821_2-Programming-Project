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

void Narrative::intro()
{
    void starter_chest_open();
    char choice;
    cout << "You wake up....";
    cont_clr();
    cout << "It's scortching hot outside";
    cont_clr();
    cout << "That was a weird dream";
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
        cout << "Open (o)\nExit(e)\n";
        cin >> choice;
        choice = tolower(choice);  
        if (choice != 'o' && choice != 'c')
            {
                cerr << "Invalid input please try again\n";
                cont_clr();
            }
            

    }while(choice == !'o' && choice == !'c');

    if(choice == 'o')
    {
        Loot loot("Ch1"); // chest 1 (starter chest) 
    }
    else if (choice == 'e')
    {
        cout << "You have exited through the front door\n";
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
    cin >> choice;
    choice = tolower(choice);
    switch (choice)
    {
        case 'a':
        system("cls");
           dialogueOneA();
           break;
        case 'r':
            cout << "You have chosen to run away\n";
          cont_clr();    //Doill or Jack you can maybe add your sequences here
            break;
    }
    
    cout << "You have entered the town, and see the big red wooden building the cowboy was talking about\n";

}

void Narrative::cont_clr()
{
    cout << "\n\n";
    system("pause");
    system("cls");
}

void Narrative::dialogueTwoA()
{
    char choice;
    cout << "Path Option:\n(A)Go to the bar\n(B)Go to the sheriff's office\n";
    cin >> choice;
    choice = tolower(choice);
    switch (choice)
    {
        case 'a':
            cout << "You have chosen to go to the bar\n";
            cont_clr();
            //Bar sequence here
            break;
        case 'b':
            cout << "You have chosen to go to the sheriff's office\n";
            cont_clr();
            //Sheriff's office sequence here
            break;
    }
}

void Narrative::dialogueOneA()
{
    char choice;
    system("cls");
    cout << "'Theres been a shootout in the bar' - Passing Cowboy\n\n";
    cout << "DIALOGUE OPTION:\n";
    cout << "'Why was there a shootout?' (w)\n";
    cout << "'Where is the bar?' (b)\n";
    cin >> choice;
    choice = tolower(choice);
    switch (choice)
    {
        case 'w':
            cout << "'I don't know, Theres always shootouts at the bar' - Passing Cowboy\n";
            system("pause");
            cout << "'I guess I should go check it out' - You\n";

        case 'b':
            cout << "'Its the big red wooden building in the middle of town'\n'You can't miss it' - Passing Cowboy\n";
            system("pause");
            cout << "'I guess I should go check it out' - You\n";

    }
}