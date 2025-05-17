#include "Game.h"
#include "raylib.h"
#include "Utils.h"
#include <cstdlib>
#include <ctime>


Game::Game() : running(true), score(0), lives(3), player({400, 300}) {
    srand((unsigned int)time(NULL));
    InitWindow(800, 600, "Asteroids");
    Init();
}

Game::~Game() {
    CloseWindow();
}

// Initialise le joueur, les listes et les astéroïdes
void Game::Init() {
    player = Player({400, 300});
    bullets.clear();
    asteroids.clear();
    SpawnAsteroids(8);
}

// Ajoute des astéroïdes à des positions aléatoires
void Game::SpawnAsteroids(int count) {
    for (int i = 0; i < count; ++i)
        asteroids.emplace_back(GetRandomPosition());
}

// Boucle principale du jeu
void Game::Run() {
    while (!WindowShouldClose() && running) {
        Update();
        Draw();
    }
}

// Met à jour tous les objets et gère les entrées
void Game::Update() {
    player.Update();
    if (IsKeyPressed(KEY_SPACE))
        bullets.push_back(player.Shoot());
    for (auto& bullet : bullets)
        bullet.Update();
    for (auto& asteroid : asteroids)
        asteroid.Update();
    CheckCollisions();
    if (lives <= 0)
        Reset();
}

// Dessine tous les éléments du jeu
void Game::Draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    player.Draw();
    for (auto& bullet : bullets)
        bullet.Draw();
    for (auto& asteroid : asteroids)
        asteroid.Draw();
    DrawText(TextFormat("SCORE: %d", score), 20, 20, 20, WHITE);
    DrawText(TextFormat("LIVES: %d", lives), 680, 20, 20, WHITE);
    EndDrawing();
}

// Gère les collisions entre projectiles, astéroïdes et joueur
void Game::CheckCollisions() {
    // Collisions bullets/asteroids
    for (size_t i = 0; i < bullets.size(); ++i) {
        for (size_t j = 0; j < asteroids.size(); ++j) {
            if (CheckCollisionCircles(bullets[i].GetPosition(), 5, asteroids[j].GetPosition(), asteroids[j].GetRadius())) {
                bullets.erase(bullets.begin() + i);
                asteroids.erase(asteroids.begin() + j);
                score += 100;
                return;
            }
        }
    }
    // Collisions player/asteroids
    for (auto& asteroid : asteroids) {
        if (CheckCollisionCircles(player.GetPosition(), 20, asteroid.GetPosition(), asteroid.GetRadius())) {
            lives--;
            player = Player({400, 300});
            return;
        }
    }
    
    if (asteroids.empty())
        SpawnAsteroids(10);
}

// Remet le jeu à zéro
void Game::Reset() {
    score = 0;
    lives = 3;
    Init();
}
