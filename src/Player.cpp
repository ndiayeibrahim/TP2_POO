#include "Player.h"
#include "raylib.h"
#include <cmath>


Player::Player(Vector2 startPos) : position(startPos), rotation(0), speed(2.5f) {}


void Player::Update() {
    if (IsKeyDown(KEY_LEFT)) rotation -= 3.0f;
    if (IsKeyDown(KEY_RIGHT)) rotation += 3.0f;
    if (IsKeyDown(KEY_UP)) {
        position.x += cosf(rotation * DEG2RAD) * speed;
        position.y += sinf(rotation * DEG2RAD) * speed;
    }
   
    if (position.x > 800) position.x = 0;
    if (position.x < 0) position.x = 800;
    if (position.y > 600) position.y = 0;
    if (position.y < 0) position.y = 600;
}


void Player::Draw() {
    Vector2 p1 = { position.x + cosf((rotation - 90) * DEG2RAD) * 20.0f, position.y + sinf((rotation - 90) * DEG2RAD) * 20.0f };
    Vector2 p2 = { position.x + cosf((rotation + 140) * DEG2RAD) * 20.0f, position.y + sinf((rotation + 140) * DEG2RAD) * 20.0f };
    Vector2 p3 = { position.x + cosf((rotation + 220) * DEG2RAD) * 20.0f, position.y + sinf((rotation + 220) * DEG2RAD) * 20.0f };
    DrawTriangleLines(p1, p2, p3, WHITE);
}

Bullet Player::Shoot() const {
    Vector2 dir = { cosf(rotation * DEG2RAD), sinf(rotation * DEG2RAD) };
    return Bullet(position, dir);
}
