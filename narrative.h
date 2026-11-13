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
    char typingText(std::string text, int delay);
public:
    Narrative();
    ~Narrative();

    void intro();
    void cont_clr();
    


};