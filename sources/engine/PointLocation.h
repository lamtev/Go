#ifndef GO_POINTLOCATION_H
#define GO_POINTLOCATION_H

namespace Go {

enum class VerticalCoordinate {
  A=1, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
};
using HorizontalCoordinate = short;

class PointLocation {
 public:
  constexpr PointLocation(VerticalCoordinate verticalCoordinate = VerticalCoordinate::A,
                          HorizontalCoordinate horizontalCoordinate = 1) noexcept
      : verticalCoordinate{verticalCoordinate},
        horizontalCoordinate{horizontalCoordinate} { }

  constexpr VerticalCoordinate getVerticalCoordinate() noexcept {
    return verticalCoordinate;
  }

  constexpr int getVerticalCoordinate() const noexcept {
    return static_cast<int>(verticalCoordinate);
  }

  constexpr HorizontalCoordinate getHorizontalCoordinate() const noexcept {
    return horizontalCoordinate;
  }

  constexpr bool operator==(const PointLocation &pointLocation) const noexcept {
    return
        verticalCoordinate == pointLocation.verticalCoordinate &&
        horizontalCoordinate == pointLocation.horizontalCoordinate;
  }

  constexpr bool operator!=(const PointLocation &pointLocation) const noexcept {
    return !(*this == pointLocation);
  }

 private:
  VerticalCoordinate verticalCoordinate;
  HorizontalCoordinate horizontalCoordinate;
};

}

#endif //GO_POINTLOCATION_H