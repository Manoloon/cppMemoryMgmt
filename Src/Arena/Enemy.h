#pragma once
#include <string>
#define HOMEMADE_VERSION
#include <cstddef>
#include <new>

class Enemy{
    std::string name = "Enemy";
    int strength = 100;
    double health = 100.0;

    public:
    static constexpr int NB_MAX = 1000000;
    #ifdef HOMEMADE_VERSION
        void* operator new(std::size_t n);
        void* operator new[](std::size_t n);
        void operator delete(void* p) noexcept;
        void operator delete[](void* p) noexcept;
    #endif
};