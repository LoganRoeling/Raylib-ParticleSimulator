#include "Vec2.hpp"

Vec2::Vec2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vec2 Vec2::add(Vec2 other) {
    return Vec2(this->x + other.x, this->y + other.y);
}

Vec2 Vec2::sub(Vec2 other) {
    return Vec2(this->x - other.x, this->y - other.y);
}

Vec2 Vec2::scale(float scalar) {
    return Vec2(this->x * scalar, this->y * scalar);
}

float Vec2::dot(Vec2 other) { return this->x * other.x + this->y * other.y; }
