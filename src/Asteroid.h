#pragma once
#include "raylib.h"

class Asteroid {
private:
    Vector2 position;  
    Vector2 velocity;   
    float radius;     

public:
    Asteroid(Vector2 pos);
    void Update();
    void Draw();

    Vector2 GetPosition() const { return position; }
    float GetRadius() const { return radius; }
};
