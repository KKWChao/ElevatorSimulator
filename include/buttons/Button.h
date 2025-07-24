#ifndef BUTTON_H
#define BUTTON_H

class Button {
    public:
        Button();
        
        virtual void setPress() = 0;
        virtual void reset(); 
        bool getPress() const { return this->pressed; }
    protected:
        bool pressed; 
};

#endif