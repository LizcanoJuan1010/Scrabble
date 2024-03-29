#ifndef LETRA_H
#define LETRA_H

#include <string>

class Letter {
private:
    char character;
    int value;

public:
    Letter(char character, int value);
    char getCharacter() const;
    int getValue() const;
};

#endif // LETRA_H
