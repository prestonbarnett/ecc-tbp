//
// Created by preston on 10/22/2023.
//

#include "PointInteger.h"

PointInteger::PointInteger(const Integer& x, const Integer& y, const Integer& a, const Integer& b, const bool& inf) :
  x(x), y(y), a(a), b(b), infinity(inf) {
    if (this->y * this->y != this->x * this->x * this->x + this->a * this->x + this->b && !infinity) {
        throw std::runtime_error("Point is not on the curve");
    }
}

PointInteger PointInteger::operator+(const PointInteger &other) {
    if (this->a != other.a || this->b != other.b) {
        throw std::runtime_error("Points are not on the same curve");
    }

    if (this->infinity) {
        return other;
    }
    if (other.infinity) {
        return *this;
    }

    if (this->x == other.x && this->y != other.y) {
        return {0, 0, this->a, this->b, true};
    }

    if (this->x != other.x) {
        Integer s = (other.y - this->y) / (other.x - this->x);
        Integer _x = (s * s) - this->x - other.x;
        Integer _y = s * (this->x - _x) - this->y;
        return {_x, _y, this->a, this->b};
    }

    if (*(this) == other && this->y == this->x * 0) {
        return {0, 0, this->a, this->b, true};
    }

    if (*(this) == other) {
        Integer s = (3 * (this->x * this->x) + this->a) / (2 * this->y);
        Integer _x = (s * s) - 2 * this->x;
        Integer _y = s * (this->x - _x) - this->y;
        return {_x, _y, this->a, this->b};
    }

    return {0, 0, this->a, this->b, true};
}

bool operator==(const PointInteger &lhs, const PointInteger &rhs) {
    return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.a == rhs.a && lhs.b == rhs.b) || (lhs.infinity && rhs.infinity);
}

bool operator!=(const PointInteger &lhs, const PointInteger &rhs) {
    return !(lhs == rhs);
}

ostream &operator<<(ostream &os, const PointInteger &p) {
    if (p.infinity) {
        os << "Point(Infinity)";
        return os;
    }

    os << "Point(" << p.x << "," << p.y << ")_" << p.a << "_" << p.b;

    return os;
}