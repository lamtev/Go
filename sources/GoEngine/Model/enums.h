#ifndef ENUMS_H
#define ENUMS_H

//todo лучше раскидать все енамы и константы по соответсвующим классам, а этот файл удалить

enum class Status
{
    EMPTY = 0,
    BLACK,
    WHITE
};

enum LiteralCoordinate
{
    A = 1,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z
};

enum Rules
{
    JAPANESE = 0,
    CHINESE
};

enum ColorDistribution
{
    NIGIRI = 0,
    AGREEMENT
};

constexpr int PASS_COORD{ -1 };

#endif // ENUMS_H
