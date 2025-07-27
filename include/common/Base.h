#ifndef BASE_H
#define BASE_H

class Base {
    public:
        virtual ~Base() = default;
        virtual void printInfo() const = 0;
    private:
};

#endif