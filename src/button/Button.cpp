#include <iostream>
#include "buttons/Button.h"

Button::Button() {
    this->pressed = false;
}

void Button::setPress() {
    this->pressed = true;
}

void Button::reset() {
    this->pressed = false;
}

