#ifndef VEC2_H
#define VEC2_H

class Vec2 {
   private:
   public:
    float x;
    float y;
    Vec2(float x = 0.0f, float y = 0.0f);
    Vec2 add(Vec2 other);
    Vec2 sub(Vec2 other);
    Vec2 scale(float scalar);
    float dot(Vec2 other);
};

#endif
