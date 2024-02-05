#include "../include/Zombie.h"

const int N = 4;
int main()
{

    Zombie* zombis = zombieHorde(N, "Putrefacto");

    for (int i = 0; i < N; i++) {
        zombis[i].announce();
    }

   delete[] zombis;
    return 0;
}