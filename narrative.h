#pragma once

#include <string>
#include <iostream>


class Narrative{
private:
    void outside_house();
    void dialogueOneA();
    void dialogueTwoA();
    void minidialogue();
    void ranAway();
    void DoillSequence();
public:

    Narrative();
    ~Narrative();
    
    void typingText(std::string text, int delay);
    void intro();
    void cont_clr();
    
    //area dialogue - public so we can call them
    void homeDialougue();
    void barDialogue();
    void shticksDialogue();
    void churchDialogue();
    void caveDialogue();

};