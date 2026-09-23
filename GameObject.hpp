#pragma once
#include <string>
#include <ostream>
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
    friend std::ostream& operator<<(std::ostream& out, const GameObject& obj);
    GameObject(std::string nme, int hlth, float xpos, float ypos, int frame); 
    void move(float dx, float dy);
    void takeDamage(int amount); 
    friend class ScriptEngine; 
    friend bool operator==(const GameObject& a, const GameObject& b);
    friend std::string stringify(const GameObject& obj);
    friend bool operator==(const Position& pos, const GameObject& obj);

};