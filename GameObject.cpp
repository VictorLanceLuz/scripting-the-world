#include "GameObject.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const GameObject& obj) {
    out << "GameObject[name=" << obj.name
        << ", health=" << obj.health
        << ", pos=(" << obj.x << "," << obj.y << ")"
        << ", animationFrame=" << obj.animationFrame << "]";
    return out;
}

GameObject::GameObject(std::string nme, int hlth, float xpos, float ypos, int frame)
    : name(nme), health(hlth), x(xpos), y(ypos), animationFrame(frame) {}

void GameObject::move(float dx, float dy) {
    x += dx;
    y += dy;
}

void GameObject::takeDamage(int amount) {
    health -= amount; 
    std::cout << name << " took " << amount << " damage. Health now: " << health << std::endl;
}
