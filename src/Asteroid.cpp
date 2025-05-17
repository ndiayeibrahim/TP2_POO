#include "Asteroid.h"
#include "Utils.h"
#include "raylib.h"

Asteroid::Asteroid(Vector2 pos) : position(pos), radius(30.0f) {
  
    velocity = { GetRandomFloat(-2.0f, 2.0f), GetRandomFloat(-2.0f, 2.0f) };
}

void Asteroid::Update() {
    position.x += velocity.x;
    position.y += velocity.y;

    if (position.x > 800) position.x = 0;
    if (position.x < 0) position.x = 800;
    if (position.y > 600) position.y = 0;
    if (position.y < 0) position.y = 600;
}

void Asteroid::Draw() {
    DrawCircleV(position, radius, GRAY);
}
