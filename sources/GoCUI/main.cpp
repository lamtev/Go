#include <iostream>

#include "GoGame.h"

int main(int argc, char *argv[]) {
  GoGame game{argc, argv};
  game.begin();
  return 0;
}
