#ifndef GO_STONE_H
#define GO_STONE_H

namespace Go {

class Stone {
 public:
  constexpr Stone(StoneColor color) noexcept
      : color(color) { }

  constexpr StoneColor getColor() const noexcept {
    return color;
  }

 private:
  enum class StoneColor {
    BLACK = 1,
    WHITE
  };

  StoneColor color;
};

}

#endif //GO_STONE_H
