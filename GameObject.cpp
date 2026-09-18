#include "GameObject.hpp"
#include <iostream>

ostream& operator<<(ostream& out, const GameObject& obj) {
    out << "GameObject[name=" << obj.name
        << ", health=" << obj.health
        << ", pos=(" << obj.x << "," << obj.y << ")"
        << ", animationFrame=" << obj.animationFrame << "]";
    return out;
}