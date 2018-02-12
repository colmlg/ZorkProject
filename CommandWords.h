#ifndef COMMANDWORDS_H_
#define COMMANDWORDS_H_
#include <iostream>
#include <string>
#include <vector>

class CommandWords {
private:
    //Define a static vector for our valid command words.
    //We'll populate this in the class constructor
    static std::vector<std::string> validCommands;

public:
    CommandWords();
    bool isCommand(std::string aString);
    void showAll();
};


#endif /*COMMANDWORDS_H_*/
