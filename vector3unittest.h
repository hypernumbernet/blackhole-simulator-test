#pragma once

#include <QtTest>
#include "../blackhole-simulator/hnn/vector3.h"

using namespace hnn;

class Vector3UnitTest
{
public:
    Vector3UnitTest();

    void test_constructor();
    void test_operator();
    void test_func();
    void test_constexpr();

    static Vector3<double> ce01()
    {
        Vector3<double> v1(0.6, 3.0, 2.0);
        return v1;
    }

    static Vector3<double> ce02()
    {
        return {1,2,3};
    }

    static Vector3<double> ce03()
    {
        Vector3<double> v1(1,2,3);
        Vector3<double> v2(4,5,6);
        auto v3 = v2 + v1;
        return v3;
    }

    static Vector3<double> ce05(const Vector3<double>& v1)
    {
        return Vector3<double>(v1 * 2);
    }
};
