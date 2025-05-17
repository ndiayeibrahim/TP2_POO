#pragma once
#include "raylib.h"

class Bullet {
private:
    Vector2 position;  
    Vector2 direction;  
    float speed;      
public:
    Bullet(Vector2 pos, Vector2 dir);

    void Update();

    void Draw();
    Vector2 GetPosition() const { return position; }
};
