#ifndef GO_STONE_H
#define GO_STONE_H

class Stone {
 public:
  enum class StoneColor {
    BLACK = 1,
    WHITE
  };

  constexpr Stone(StoneColor color) noexcept
  : color(color) {}

  constexpr StoneColor getColor() const noexcept {
    return color;
  }

 private:
  StoneColor color;
};


#endif //GO_STONE_H
