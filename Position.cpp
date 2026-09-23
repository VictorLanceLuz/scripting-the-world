#include "Position.hpp"

Position::Position(float xVal, float yVal) : x(xVal), y(yVal) {}

bool operator==(const Position &pos, const GameObject &obj)
{
    return false;
}
