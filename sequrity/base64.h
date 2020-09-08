//______  _______ _______ _______ _______ _______
//|     \ |______    |    |______ |_____| |  |  |
//|_____/.______| .  |    |______ |     | |  |  |
// Copyright (c) 2020 Dark Shield Team. All rights reserved.
// Created by moonlin on 007 07.09.20 at 21:35.

/*
 Алгоритм работы
    Изначально на вход поступает массив байт,
    каждый байт — это число от 0 до 255,
    то есть максимальное количество бит в числе равно восьми
    (255 в двоичной системе счисления это 11111111).
    Необходимо взять 3 байта(это 24 бита),
    которые разбивают на 4 части – по 6 бит.
    Число из 6 бит (в десятичной системе) и будет представлять
    из себя очередной индекс в таблице для получения
    символа кодирования (6 бит – в двоичном виде 111111,
    в десятичном виде это число 63). Если размер исходного массива
    не кратен 3, тогда итоговую строку следует
    дополнить символом = до размера кратного 3.
 */

#ifndef MAIN_BASE64_H
#define MAIN_BASE64_H

#include <string>

class base64 {
private:

protected:
    std::string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                        "abcdefghijklmnopqrstuvwxyz"
                        "0123456789+/"; //64
public:
    base64();
    static std::string encode(std::string const &in);
    static std::string decode(std::string const &in);
    ~base64();
};


#endif //MAIN_BASE64_H
