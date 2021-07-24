#pragma once

#include <QtTest>
#include <QQuaternion>

#include "../blackhole-simulator/hnn/quaternion.h"

using namespace hnn;

class QuaternionUnitTest
{
public:
    QuaternionUnitTest();

    void test_member();
    void test_constructor();
    void test_set();
    void test_operator();
    void test_zero();
    void test_ln();
    void test_norm();
};
