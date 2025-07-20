#include <iostream>
#include "Button.h"

Button::Button() {
    this->pressed = false;
}

void Button::setPress(bool press) {
    this->pressed = press;
}

void Button::reset() {
    this->pressed = false;
}

bool Button::getPress() const {
    return pressed;
}

