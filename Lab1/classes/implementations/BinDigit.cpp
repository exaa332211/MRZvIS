//
// Created by Panin Aleksey and Kandyba Egor on 5/26/20.
//std::string digit;
//    unsigned _digit;
//    char sign;
//    unsigned shift_amount{};

#include "../headers/BinDigit.h"
#include <iostream>

#include <bitset>

BinDigit::BinDigit(std::string digit, SIGN sign) : shift_amount(0), digit(std::bitset<15>(digit).to_string()), sign(sign),
                                                   _digit(BinDigit::getDecimalDigitInt(digit)) {}

BinDigit::BinDigit(unsigned digit, SIGN sign) : shift_amount(0), _digit(digit), sign(sign), digit(BinDigit::getBinDigitStr(digit)) {}

BinDigit &BinDigit::operator+(const BinDigit &obj)
{
    int buffer = 0;
    if (this->sign == NEGATIVE || obj.sign == NEGATIVE)
    {
        int f = (int)this->_digit, s = (int)obj._digit;
        if (this->sign == NEGATIVE)
            f = -f;
        if (obj.sign == NEGATIVE)
            s = -s;
        buffer = f + s;
    }
    else
    {
        buffer = this->_digit + obj._digit;
    }
    buffer >= 0 ? this->sign = BinDigit::POSITIVE : this->sign = BinDigit::NEGATIVE;
    this->_digit = (buffer >= 0 ? buffer : -buffer);
    this->digit = BinDigit::getBinDigitStr(this->getDigitDecimal());
    return *this;
}

const std::string &BinDigit::getDigitBinary() const
{
    return digit;
}

unsigned BinDigit::getDigitDecimal() const
{
    return _digit;
}

char BinDigit::getSign() const
{
    return sign;
}

std::string BinDigit::getBinDigitStr(unsigned digit)
{
    return std::bitset<15>(digit).to_string();
}

unsigned BinDigit::getDecimalDigitInt(std::string &binDigit)
{
    return std::bitset<15>(binDigit).to_ulong();
}

std::string BinDigit::toString()
{
    return this->getSign() + this->getDigitBinary();
}

BinDigit &BinDigit::operator-(const BinDigit &obj)
{
    int buffer = 0;
    if (this->sign == NEGATIVE || obj.sign == NEGATIVE)
    {
        int f = (int)this->_digit, s = (int)obj._digit;
        if (this->sign == NEGATIVE)
            f = -f;
        if (obj.sign == NEGATIVE)
            s = -s;
        buffer = f - s;
    }
    else
    {
        buffer = this->_digit + obj._digit;
    }
    buffer >= 0 ? this->sign = BinDigit::POSITIVE : this->sign = BinDigit::NEGATIVE;
    this->_digit = (buffer >= 0 ? buffer : -buffer);
    this->digit = BinDigit::getBinDigitStr(this->getDigitDecimal());
    return *this;
}

BinDigit BinDigit::operator/(const BinDigit &divider)
{
    BinDigit shift_div = shiftDivider(const_cast<BinDigit &>(divider), *this); //сдвиг делитель до делимого
    BinDigit new_div(preparingForDivision(shift_div, *this));                  //перевод в доп и обратный код

    BinDigit rez = *this + new_div;
    std::string bin_result = "";
    for (int i = 0; i < divider.shift_amount; i++)
    { // процесс деления
        rez.digit = left_shift(rez.digit);
        rez._digit = BinDigit::getDecimalDigitInt(rez.digit);
        (rez.digit[0] == '1') ? bin_result += '0' : bin_result += '1';
        (bin_result.back() == '0') ? rez = rez + shift_div : rez = rez - new_div;
    }
    (rez.digit[0] == '1') ? bin_result += '0' : bin_result += '1';

    BinDigit result(bin_result, divider.getSign() == this->getSign() ? BinDigit::POSITIVE : BinDigit::NEGATIVE); // результатат деления - целочисленный
    std::cout << result.digit << std::endl;

    checkBalance(rez, const_cast<BinDigit &>(divider)); //вычисление остатка

    return result; //rez.digit - остаток от деления
}
BinDigit BinDigit::shiftDivider(BinDigit &divider, const BinDigit &dividend)
{ // сдвиг делителя до начала делимого
    unsigned bit_pos = 0;
    for (int i = 0; i < dividend.digit.length(); i++)
    {
        if (dividend.digit[i] == '1')
        {
            bit_pos = i;
            break;
        }
    }
    divider.shift_amount = 0;
    while (divider.digit[bit_pos] != '1')
    {
        divider.digit = left_shift(divider.digit);
        divider.shift_amount++;
    }
    BinDigit new_div(divider.digit, divider.getSign() >= 0 ? BinDigit::POSITIVE : BinDigit::NEGATIVE);
    return new_div;
}
BinDigit BinDigit::intoReverseCode(BinDigit &divider)
{
    for (char &i : divider.digit)
        i = (i == '0') ? '1' : '0';
    divider._digit = BinDigit::getDecimalDigitInt(divider.digit);
    return divider;
}

BinDigit BinDigit::preparingForDivision(const BinDigit &shift_div, const BinDigit &dividend)
{
    BinDigit new_div = shift_div;
    intoReverseCode(new_div);
    new_div = new_div + BinDigit(1, BinDigit::POSITIVE);
    return new_div;
}

std::string BinDigit::left_shift(std::string digit)
{
    digit += '0';
    digit.erase(0, 1);
    return digit;
}

std::string BinDigit::right_shift(std::string digit)
{
    digit.erase(digit.length() - 1, 1);
    digit[0] = '0';
    return digit;
}

BinDigit BinDigit::checkBalance(BinDigit &rez, BinDigit &divider)
{
    rez._digit = BinDigit::getDecimalDigitInt(rez.digit);
    if (rez.digit[0] == '1')
        rez = rez + divider;
    for (int i = 0; i < divider.shift_amount; i++)
    {
        rez.digit = right_shift(rez.digit);
        rez._digit = BinDigit::getDecimalDigitInt(rez.digit);
    }
    std::cout << rez.digit;
    return rez;
}

BinDigit BinDigit::start(std::vector<BinDigit> firstVector, std::vector<BinDigit> secondVector)
{

    std::vector<BinDigit> first, second;

    int takt = firstVector.size();
    std::vector<std::vector<BinDigit>> mainVector(takt, std::vector<BinDigit>(takt + 5, BinDigit(0, BinDigit::POSITIVE)));
    for (int i = 0; i < takt + 3; i++)
    {
        std::cout << "Tакт: " << i + 1 << std::endl; //1 - первое число , 2 - второе число
        if (i < takt)
        {
            mainVector[i][0] = firstVector[i];
            mainVector[i][1] = secondVector[i];
        }

        for (int k = 0; k <= i && k < takt; k++)
        { //сдвиг делитель до делимого
            if (mainVector[k][0].step == 0)
            {
                std::cout << "Пара " << k << " Превращена в двоичное" << std::endl;
                std::cout << "Число №1:" << mainVector[k][0].getDigitBinary() << std::endl;
                std::cout << "Число №2:" << mainVector[k][1].getDigitBinary() << std::endl;
                mainVector[k][0].step++;
                continue;
            }
            if (mainVector[k][0].step == 1)
            {
                BinDigit shift_div = shiftDivider(const_cast<BinDigit &>(mainVector[k][1]), mainVector[k][0]);
                mainVector[k][2] = shift_div;
                std::cout << "Пара " << k << " Произошел сдвиг делитель до делимого" << std::endl;
                std::cout << "Число №1:" << mainVector[k][0].getDigitBinary() << std::endl;
                std::cout << "Число №2:" << mainVector[k][1].getDigitBinary() << std::endl;
                mainVector[k][0].step++;
                continue;
            }
            if (mainVector[k][0].step == 2)
            {
                BinDigit new_div(preparingForDivision(mainVector[k][2], mainVector[k][0])); //перевод в доп и обратный код
                mainVector[k][3] = new_div;
                std::cout << "Пара " << k << " Произошел перевод в дополнительный или обратный код" << std::endl;
                std::cout << "Число №1:" << mainVector[k][0].getDigitBinary() << std::endl;
                std::cout << "Число №2:" << mainVector[k][1].getDigitBinary() << std::endl;
                mainVector[k][0].step++;
                continue;
            }
            if (mainVector[k][0].step == 3)
            {

                mainVector[k][4] = division(mainVector[k][3], mainVector[k][1], mainVector[k][2], mainVector[k][0]); //перевод в доп и обратный код
                std::cout << "Пара " << k << " Произошло деление" << std::endl;
                std::cout << "Число №1:" << mainVector[k][0].getDigitBinary() << std::endl;
                std::cout << "Число №2:" << mainVector[k][1].getDigitBinary() << std::endl;
                std::cout << "Результат:" << mainVector[k][4].getDigitDecimal() << std::endl;
                mainVector[k][5] = BinDigit(i * 2, (BinDigit::POSITIVE));
                mainVector[k][0].step++;
                continue;
            }
            if (mainVector[k][0].step == 4)
            {
                std::cout << "Пара " << k << " Обновить результат\n"
                          << "Результат: " << mainVector[k][4].getDigitDecimal() << "\n";
                continue;
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < takt; i++)
    {
        std::cout << "Пара " << i << " Результат  " << mainVector[i][4].getDigitDecimal()
                  << " Время - " << mainVector[i][5].getDigitDecimal() + 2 << std::endl;
    }
    return BinDigit(0, BinDigit::POSITIVE);
}

BinDigit BinDigit::division(BinDigit new_div, BinDigit divider, BinDigit shift_div, BinDigit divident)
{
    BinDigit rez = divident + new_div;
    std::string bin_result = "";
    for (int i = 0; i < divider.shift_amount; i++)
    { // процесс деления
        rez.digit = left_shift(rez.digit);
        rez._digit = BinDigit::getDecimalDigitInt(rez.digit);
        (rez.digit[0] == '1') ? bin_result += '0' : bin_result += '1';
        (bin_result.back() == '0') ? rez = rez + shift_div : rez = rez - new_div;
    }
    (rez.digit[0] == '1') ? bin_result += '0' : bin_result += '1';

    BinDigit result(bin_result, divider.getSign() == divident.getSign() ? BinDigit::POSITIVE : BinDigit::NEGATIVE); // результатат деления - целочисленный
    return result;
}
