#include <iostream>
#include <windows.h>

#include "narrative.h"
#include "loot.h"

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
    
    //Add start menu here, with options to start a new game, load a game, settings etc.
    // void startMenu();
    system("cls"); 
    cout << typingText("You wake up....", 5);
    cont_clr();
    cout << typingText("It's scortching hot outside", 5);
    cont_clr();
    cout << typingText("That was a weird dream", 5); 
    //this will lead on to the fact they have gear left on the dresser from previus run
    cont_clr();
    
    /*
     make sure to add the if: 
     if(had gear and died){cout << "There seems to be a(n) " << ...
     ITEM_FROM_DEATH << " on the dresser \n I wonder why?" << endl
     update inventory to hold item}
    */
     
    
    do{
        cout << typingText("You stand up and walk over to your storage chest...",5)<< endl;
        cout << typingText("Would you like to open it, or exit through the front door?",5) << endl;
        cout << typingText("Open (O)",1) << "\n"<< typingText("\nExit(E)\n",1)<< endl; //First dialogue option
        cin >> choice;

        choice = tolower(choice);  
        if (choice != 'o' && choice != 'e')
            {
                cerr << typingText("Please enter an shown input\n",1);
                cont_clr();
            } //if the user inputs anything other than 'o' or 'e', it will display an error message 
              //and ask them to try again
            

    }while(choice != 'o' && choice != 'e'); //while loop will keep asking the user for input until they enter a valid option

    if(choice == 'o')
    {
        Loot loot("Chest", 1); // chest 1 (starter chest) 
    }
    else if (choice == 'e')
    {
        cout << typingText("You have exited through the front door\n",5);
         // this skips the chest squence and goes straight outside with no gear.
        cont_clr();
    }

    outside_house();
}

void Narrative::outside_house()
{   
    char choice;
    cout << typingText("You have exited the house and are now in the desert\n",5);
    cont_clr();
    cout << typingText("You see a small town in the distance, you walk towards it\n",5);
    cont_clr();
    cout << typingText("The air is dry and hot, you can feel the sweat dripping down your face\n",5);
    cont_clr();
    cout << typingText("You hear a gunshot in the distance, you look around and see a small group of people running towards you\n\n",5);
    cout << typingText("DIALOGUE OPTION:\n",1);
    cout << typingText("Would you like to ask them what's going on, or run away?\n",1);
    cout << typingText("Ask (a)\n Run (r)\n",1);
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
            cout << typingText("You have chosen to run away\n",5);
            cont_clr();    
            ranAway();
            return;
    }
    
    cout << typingText("You have entered the town, and see the big red wooden building the cowboy was talking about\n",5);
    cont_clr();
    cout << typingText("You can smell the gunpowder in the air, and see smoke rising from behind the bar.\n",5);
    cont_clr();
    cout << typingText("You can hear the sound of gunfire and shouting coming from inside the bar.\n",5);
    cont_clr();
    cout << typingText("You look to your right and see the sheriff's station.",5);
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
    cout << typingText("'Theres been a shootout in the bar.' - Passing Cowboy\n\n",5);
    cout << typingText("DIALOGUE OPTION:\n",1);
    cout << typingText("'Why was there a shootout?' (w)\n",1);
    cout << typingText("'Where is the bar?' (b)\n",1);
    cin >> choice;
    choice = tolower(choice);
    //must add input checking to make sure the user inputs a valid option, if not it will ask them to try again.
    switch (choice)
    {
        case 'w':
            system("cls");
            cout << typingText("'I don't know. \n'Theres always shootouts at the bar'\n 'But I sure as hell ain't stickin' around!' - Passing Cowboy\n",5);
            system("pause");
            minidialogue();
            break;
        case 'b':
            system("cls");
            cout << typingText("'Its the big red wooden building in the middle of town'\n'You can't miss it' - Passing Cowboy\n\n",5);
            cont_clr();
            cout << typingText("'I guess I should go check it out' - You\n",5);
            cont_clr();
            break;
    }
}
void Narrative::minidialogue()
{
    char choice;
    cout << typingText("DIALOGUE OPTION:\n",1);
    cout << typingText("'Where is the bar?' (b)\n",1);
    cout << typingText(" 'Run away' (r)\n",1);
    cin >> choice;
    choice = tolower(choice);
    //must add input checking to make sure the user inputs a valid option, if not it will ask them to try again.
    switch (choice)
    {
        case 'b':
            system("cls");
            cout << typingText("'Its the big red wooden building in the middle of town'\n'You can't miss it' - Passing Cowboy\n",5);
            system("pause");
            cout << typingText("'I guess I should go check it out' - You\n",5);
            cont_clr();
            break;
        case 'r':
            system("cls");
            cout << typingText("You have chosen to run away\n",5);
            cont_clr();    
            //Doill or Jack you can maybe add your sequences here
            
            ranAway();
            break;
    }
}

void Narrative::dialogueTwoA()
{
    char choice;
    cout << typingText("Path Option:\n(A)Go to the bar\n(B)Go inside the Sheriff's office and ask why they arent doing anything\n",1);
    cin >> choice;
    choice = tolower(choice);
    //must add input checking to make sure the user inputs a valid option, if not it will ask them to try again.
    switch (choice)
    {
        case 'a':
            system("cls");
            cout << typingText("You have chosen to go into the bar\n",5);
            cont_clr();
            //Bar sequence here

            break;
        case 'b':
            system("cls");
            cout << typingText("You have chosen to go to the sheriff's office\n",5); 
            //doesnt have to be sherriffs, could be whatever you want it to be, just make sure to change the text in the cout statement above
            cont_clr();
            //Sheriff's office sequence here
            break;
    }
}

void Narrative::ranAway()
{
    cout << typingText("You flee into the crowd and disappear before the cowboy can catch up.",5)<<"\n";
    cont_clr();
}

void Narrative::DoillSequence()
{
//Doill sequence here
cout << "is this working\n";
cout << "is it stillworking ";
}

char Narrative::typingText(std::string text, int delay)
{
    for (int i = 0; i < text.length(); i++)
    {
        cout << text[i];
        Sleep(delay); // Sleep for the specified delay in milliseconds
    }
    return ' ';
}