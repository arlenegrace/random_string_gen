#pragma once

#include <random>
#include <string>

/* DECLARATIONS */
std::string gen_string(size_t size, uint8_t lower, uint8_t upper);
std::string gen_string(size_t size);
std::string gen_lower_case_string(size_t size);
std::string gen_upper_case_string(size_t size);
std::string gen_alpha_string(size_t size);
std::string gen_alnum_string(size_t size);
char gen_char(uint8_t lower, uint8_t upper);
char gen_lower_case_char();
char gen_upper_case_char();
char gen_alpha_char();
char gen_alnum_char();
char gen_integer_char();


/* IMPLEMENTATION */
std::string gen_string(size_t size, uint8_t lower, uint8_t upper)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(lower, upper);

    std::string str;
    str.reserve(size);

    for (size_t i = 0; i < size; i++) {
        str.push_back(dis(gen));
    }

    return str;
}

std::string gen_string(size_t size)
{
    return gen_string(size, 32, 126);
}

std::string gen_lower_case_string(size_t size)
{
    return gen_string(size, 97, 122);
}

std::string gen_upper_case_string(size_t size)
{
    return gen_string(size, 65, 90);
}

std::string gen_alpha_string(size_t size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(65, 122);

    std::string str;
    str.reserve(size);

    for (size_t i = 0; i < size; i++) {
        char c = dis(gen);
        while (c > 90 && c < 97)
            c = dis(gen); 

        str.push_back(c);
    }

    return str;
}

std::string gen_alnum_string(size_t size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(48, 122);

    std::string str;
    str.reserve(size);

    for (size_t i = 0; i < size; i++) {
        char c = dis(gen);
        while ((c > 90 && c < 97) || (c > 57 && c < 65))
            c = dis(gen); 

        str.push_back(c);
    }

    return str;
}

char gen_char(uint8_t lower, uint8_t upper)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(lower, upper);

    return dis(gen);
}

char gen_lower_case_char()
{
    return gen_char(97, 122);
}

char gen_upper_case_char()
{
    return gen_char(65, 90);
}

char gen_alpha_char()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(65, 122);

    char c = dis(gen);
    while (c > 90 && c < 97)
        c = dis(gen);

    return c;
}

char gen_alnum_char()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(48, 122);

    char c = dis(gen);
        while ((c > 90 && c < 97) || (c > 57 && c < 65))
        c = dis(gen);

    return c;
}

char gen_integer_char()
{
    return gen_char(48, 57);
}