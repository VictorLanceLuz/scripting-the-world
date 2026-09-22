#pragma once
#include <string>
#include "ScriptEngine.hpp"
#include "Position.hpp"

class GameObject {
private:
    std::string name;
    int health;
    float x;
    float y;
    int animationFrame;
public:
    friend ostream& operator<<(ostream& out, const GameObject& obj);
    GameObject(std::string nme, int hlth, float xpos, float ypos, int frame); 
    void move(float dx, float dy);
    void takeDamage(int amount); 
    friend class ScriptEngine; 
};