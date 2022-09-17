
#ifndef INC_2_3_0_DATA_H
#define INC_2_3_0_DATA_H

struct Data {
    unsigned int interest;
    unsigned int gain;
    unsigned int difficulty;
    unsigned int daysTo;

    Data();

    explicit Data(unsigned int difficulty);

    Data& operator= (const Data& d);

    friend bool operator< (const Data &d1, const Data &d2);

    friend bool operator== (const Data &c1, const Data &c2);
};

#endif
