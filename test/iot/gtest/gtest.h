

#ifndef __GTEST_H__
#define __GTEST_H__

#include <AUnit.h>
#include <aunit/contrib/gtest.h>

#define ASSERT_GE(e, a) assertMoreOrEqual(static_cast<decltype(a)>(e), a)

#endif
