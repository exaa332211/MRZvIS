//
// Created by Panin Aleksey and Kandyba Egor on 5/26/20.
//

#ifndef TRANPORTER_BINDIGIT_H
#define TRANPORTER_BINDIGIT_H

#include <string>

#include <vector>
class BinDigit
{
private:
    std::string digit;
    unsigned _digit;
    char sign;
    unsigned shift_amount{};

    static std::string getBinDigitStr(unsigned digit);
    static unsigned getDecimalDigitInt(std::string &binDigit);

public:
    int step = 0;
    enum SIGN
    {
        POSITIVE = '0',
        NEGATIVE = '1'
    };
    BinDigit(unsigned digit, SIGN sign);

    BinDigit(std::string digit, SIGN sign);
    BinDigit start(std::vector<BinDigit>, std::vector<BinDigit>);
    std::string toString();

    BinDigit &operator+(const BinDigit &);

    BinDigit &operator-(const BinDigit &);

    BinDigit operator/(const BinDigit &);

    const std::string &getDigitBinary() const;

    unsigned getDigitDecimal() const;

    char getSign() const;

    BinDigit division(BinDigit new_div, BinDigit divider, BinDigit shift_div, BinDigit);
};

#endif //TRANPORTER_BINDIGIT_H
