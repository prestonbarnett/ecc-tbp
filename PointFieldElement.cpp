//
// Created by preston on 10/22/2023.
//

#include "PointFieldElement.h"

#include <utility>

PointFieldElement::PointFieldElement(FieldElement x, FieldElement y, FieldElement a,
                                     FieldElement b, const bool& inf) :
        x(std::move(x)), y(std::move(y)), a(std::move(a)), b(std::move(b)), infinity(inf) {
    if (this->y * this->y != this->x * this->x * this->x + this->a * this->x + this->b && !infinity) {
        throw std::runtime_error("Point is not on the curve");
    }
}

PointFieldElement::PointFieldElement() = default;

PointFieldElement PointFieldElement::operator+(const PointFieldElement &other) {
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
        return {FieldElement(0, this->x.getPrime()),
                FieldElement(0, this->x.getPrime()), this->a, this->b, true};
    }

    if (this->x != other.x) {
        FieldElement otherY = other.y;
        FieldElement otherX = other.x;
        FieldElement s = (otherY - this->y) / (otherX - this->x);
        FieldElement _x = (s * s) - this->x - other.x;
        FieldElement _y = s * (this->x - _x) - this->y;
        return {_x, _y, this->a, this->b};
    }

    if (*(this) == other && this->y == this->x * 0) {
        return {FieldElement(0, this->x.getPrime()),
                FieldElement(0, this->x.getPrime()), this->a, this->b, true};
    }

    if (*(this) == other) {
        FieldElement s = ((this->x * this->x) * 3 + this->a) / (this->y * 2);
        FieldElement _x = (s * s) - this->x * 2;
        FieldElement _y = s * (this->x - _x) - this->y;
        return {_x, _y, this->a, this->b};
    }

    return {FieldElement(0, this->x.getPrime()),
            FieldElement(0, this->x.getPrime()), this->a, this->b, true};
}

bool operator==(const PointFieldElement &lhs, const PointFieldElement &rhs) {
    return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.a == rhs.a && lhs.b == rhs.b) || (lhs.infinity && rhs.infinity);
}

bool operator!=(const PointFieldElement &lhs, const PointFieldElement &rhs) {
    return !(lhs == rhs);
}

ostream &operator<<(ostream &os, const PointFieldElement &p) {
    if (p.infinity) {
        os << "Point(Infinity)";
        return os;
    }

    os << "Point(" << p.x << "," << p.y << ")_" << p.a << "_" << p.b << " FieldElement(" << p.x.getPrime() << ")";

    return os;
}

PointFieldElement PointFieldElement::operator*(const Integer &other) {
    Integer coef = other;

    PointFieldElement current = *this;
    PointFieldElement result = PointFieldElement(FieldElement(0, this->x.getPrime()),
                                                 FieldElement(0, this->x.getPrime()),
                                                 this->a, this->b, true);

    while (!coef.IsZero()) {
        if (coef.IsOdd()) {
            result = result + current;
        }
        current = current + current;
        coef >>= 1;
    }

    return result;
}

bool PointFieldElement::isInfinity() const {
    return this->infinity;
}

const FieldElement &PointFieldElement::getX() const {
    return x;
}

const FieldElement &PointFieldElement::getY() const {
    return y;
}

const FieldElement &PointFieldElement::getA() const {
    return a;
}

const FieldElement &PointFieldElement::getB() const {
    return b;
}
