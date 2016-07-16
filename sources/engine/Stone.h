#ifndef GO_STONE_H
#define GO_STONE_H

namespace Go {

enum class StoneColor {
  BLACK = 1,
  WHITE
};

class Stone {
 public:
  explicit constexpr Stone(StoneColor color = StoneColor::BLACK) noexcept
      : color{color} { }

  constexpr Stone(const Stone &stone) noexcept
      : color{stone.color} { }

  constexpr StoneColor getColor() const noexcept {
    return color;
  }

  constexpr bool operator==(const Stone &stone) const noexcept {
    return color == stone.color;
  }

  constexpr bool operator!=(const Stone& stone) const noexcept {
    return !(*this == stone);
  }

 private:
  StoneColor color;
};

}

#endif //GO_STONE_H
