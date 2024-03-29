#include "Letter.h"

Letter::Letter(char character, int value) : character(character), value(value) {}

char Letter::getCharacter() const {
    return character;
}

int Letter::getValue() const {
    return value;
}
