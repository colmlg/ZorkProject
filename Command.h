#ifndef COMMAND_H_
#define COMMAND_H_
#include <string>

class Command {
private:
    std::string commandWord;
    std::string secondWord;

public:
    Command(std::string firstWord, std::string secondWord);
    std::string getCommandWord();
    std::string getSecondWord();
    bool isUnknown();
    bool hasSecondWord();
};

#endif /*COMMAND_H_*/
