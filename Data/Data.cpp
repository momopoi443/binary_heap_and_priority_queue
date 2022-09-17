
#include "Data.h"
#include <random>

Data::Data() {
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_int_distribution<unsigned int> dist(0, 1'000'000'000);
    this->interest = 0;
    this->gain = 0;
    this->difficulty = dist(mt);
    this->daysTo = 0;
}

Data::Data(unsigned int difficulty) {
    this->interest = 0;
    this->gain = 0;
    this->difficulty = difficulty;
    this->daysTo = 0;
}

Data& Data::operator= (const Data& d) {
    if (this == &d)
        return *this;

    interest = d.interest;
    gain = d.gain;
    difficulty = d.difficulty;
    daysTo = d.daysTo;

    return *this;
}

bool operator< (const Data &d1, const Data &d2) {
    return d1.difficulty < d2.difficulty;
}

bool operator== (const Data &d1, const Data &d2) {
    return d1.difficulty == d2.difficulty;
}