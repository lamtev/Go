#ifndef GO_STONE_H
#define GO_STONE_H

namespace Go {

enum class StoneColor {
  BLACK = 1,
  WHITE
};

class Stone {
 public:
  Stone(StoneColor color = StoneColor::BLACK) noexcept
      : color(color) { }

  StoneColor getColor() const noexcept {
    return color;
  }

  bool operator==(const Stone &stone) const noexcept {
    return color == stone.color;
  }

  bool operator!=(const Stone& stone) const noexcept {
    return !(*this == stone);
  }

 private:
  StoneColor color;
};

}

#endif //GO_STONE_H
