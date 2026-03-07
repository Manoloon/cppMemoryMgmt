#include "Enemy.h"
#include "SizeBasedArena.h"
#ifdef HOMEMADE_VERSION
#include <cassert>
#include <cstdlib>
#include <mutex>

using Horde = SizeBasedArena<Enemy, Enemy::NB_MAX>;

void* Enemy::operator new(std::size_t n)
{
	return Horde::get().allocate_one();
}

void* Enemy::operator new[](std::size_t n)
{
	return Horde::get().allocate_n(n / sizeof(Enemy));
}

void Enemy::operator delete(void* p) noexcept
{
    Horde::get().deallocate_one(p);
}

void Enemy::operator delete[](void* p) noexcept
{
    Horde::get().deallocate_n(p);
}
#endif