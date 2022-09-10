#include "octonionunittest.h"
#include "../blackhole-simulator/hnn/octonion.h"
#include <QtTest>

using namespace hnn;

OctonionUnitTest::OctonionUnitTest()
{

}
void OctonionUnitTest::test_member()
{
    Octonion o0(0,0,0,0,1,2,3,4);
    o0.normalize();
    Octonion o1(3,4,5,6,0,0,0,0);
    o1.normalize();

    auto o2(o1.conjugated() * o0 * o1);
    QVERIFY(o2.re() == 0.0);
    QVERIFY(o2.i1() == 0.0);
    QVERIFY(o2.i2() == 0.0);
    QVERIFY(o2.i3() == 0.0);
}
