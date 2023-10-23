//
// Created by preston on 10/22/2023.
//

#include "FieldElement.h"

FieldElement::FieldElement(const Integer& num, const Integer& prime) : num(num), prime(prime) {
    if (num >= prime || num < 0) {
        throw std::invalid_argument("Num is out of range");
    }
}

FieldElement::FieldElement() = default;

ostream &operator<<(ostream &os, const FieldElement &a) {
    os << "FieldElement_" << a.prime << "(" << a.num << ")";
    return os;
}

FieldElement FieldElement::operator+(const FieldElement &other) {
    if (this->prime != other.prime) {
        throw std::runtime_error("Cannot add two numbers in different fields");
    }

    Integer calculatedAdd = (this->num + other.num) % this->prime;

    return { calculatedAdd, this->prime };
}

FieldElement FieldElement::operator-(const FieldElement &other) {
    if (this->prime != other.prime) {
        throw std::runtime_error("Cannot subtract two numbers in different fields");
    }

    Integer calculatedSub = (this->num - other.num) % this->prime;

    return { calculatedSub, this->prime };
}

FieldElement FieldElement::operator*(const FieldElement &other) {
    if (this->prime != other.prime) {
        throw std::runtime_error("Cannot multiply two numbers in different fields");
    }

    Integer calculatedMul = (this->num * other.num) % this->prime;

    return { calculatedMul, this->prime };
}

FieldElement FieldElement::operator*(const Integer &other) {
    Integer calculatedMul = (this->num * other) % this->prime;

    return { calculatedMul, this->prime };
}

FieldElement FieldElement::operator*(int other) {
    Integer calculatedMul = (this->num * other) % this->prime;

    return { calculatedMul, this->prime };
}

FieldElement FieldElement::operator/(const FieldElement &other) {
    if (this->prime != other.prime) {
        throw std::runtime_error("Cannot divide two numbers in different fields");
    }
    Integer calculatedDiv = (this->num * (a_exp_b_mod_c(other.num, this->prime - 2, this->prime))) % this->prime;

    return { calculatedDiv, this->prime };
}

FieldElement FieldElement::power(const Integer &exp) {
    Integer power = exp;
    Integer base = this->num;
    if (exp.IsNegative()) {
        base = this->num.InverseMod(this->prime);
        power = exp.AbsoluteValue();
    }
    Integer calculatedPow = a_exp_b_mod_c(base, power, this->prime);

    return { calculatedPow, this->prime };
}

bool operator==(const FieldElement &lhs, const FieldElement &rhs) {
    return lhs.num == rhs.num && lhs.num == rhs.num;
}

bool operator!=(const FieldElement &lhs, const FieldElement &rhs) {
    return !(lhs == rhs);
}

Integer FieldElement::getNum() const {
    return this->num;
}

Integer FieldElement::getPrime() const {
    return this->prime;
}
