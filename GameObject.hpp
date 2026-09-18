#pragma once
#include <string>
#include "ScriptEngine.hpp"
#include "Position.hpp"

class GameObject {
private:
public:
    friend ostream& operator<<(ostream& out, const GameObject& obj);
};