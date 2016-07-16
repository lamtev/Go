#ifndef GO_POINTLOCATION_H
#define GO_POINTLOCATION_H

namespace Go {

enum class VerticalCoordinate {
  A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
};
using HorizontalCoordinate = short;

class PointLocation {
 public:
  constexpr PointLocation(VerticalCoordinate verticalCoordinate = VerticalCoordinate::A,
                          HorizontalCoordinate horizontalCoordinate = 1) noexcept
      : verticalCoordinate{verticalCoordinate},
        horizontalCoordinate{horizontalCoordinate} { }

  constexpr VerticalCoordinate getVerticalCoordinate() const noexcept {
    return verticalCoordinate;
  }

  constexpr HorizontalCoordinate getHorizontalCoordinate() const noexcept {
    return horizontalCoordinate;
  }

 private:
  VerticalCoordinate verticalCoordinate;
  HorizontalCoordinate horizontalCoordinate;
};

}

#endif //GO_POINTLOCATION_H
