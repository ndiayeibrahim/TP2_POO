#pragma once
#include "raylib.h"
#include "Bullet.h"

class Player {
private:
    Vector2 position;  
    float rotation;    
    float speed;        

public:
    
    Player(Vector2 startPos);

   
    void Update();
    void Draw();
   
    Bullet Shoot() const;
    Vector2 GetPosition() const { return position; }
};
