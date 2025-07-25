#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "3ds.h"

class InputManager {
private:
    u32 kDown;
    u32 kHeld;

public:
    InputManager();
    void scanInput();
    bool isButtonPressed(u32 button) const;
    bool isTouchDown() const;
};

#endif
