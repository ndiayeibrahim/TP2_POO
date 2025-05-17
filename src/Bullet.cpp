#include "Bullet.h"
#include "raylib.h"

Bullet::Bullet(Vector2 pos, Vector2 dir) : position(pos), direction(dir), speed(6.0f) {}

void Bullet::Update() {
    position.x += direction.x * speed;
    position.y += direction.y * speed;
    
}

void Bullet::Draw() {
    DrawCircleV(position, 5, YELLOW);
}
