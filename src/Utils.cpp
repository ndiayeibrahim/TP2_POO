#include "Utils.h"
#include <cstdlib>


float GetRandomFloat(float min, float max) {
    return min + ((float)rand() / RAND_MAX) * (max - min);
}

// Génère une position aléatoire sur l'écran
Vector2 GetRandomPosition() {
    Vector2 pos;
    pos.x = (float)GetRandomValue(0, 800);
    pos.y = (float)GetRandomValue(0, 600);
    return pos;
}
