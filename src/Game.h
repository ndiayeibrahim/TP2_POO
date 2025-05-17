#pragma once
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"
#include <vector>

class Game {
private:
    bool running;
    int score;
    int lives;
    Player player;
    std::vector<Bullet> bullets;
    std::vector<Asteroid> asteroids;
    void Init();
    void Update();
    void Draw();
    void SpawnAsteroids(int count);
    void CheckCollisions();
    void Reset();

public:
    Game();
    ~Game();
    void Run();
};
