#include "biquaternionunittest.h"
#include "../blackhole-simulator/hnn/biquaternion.h"
#include "../blackhole-simulator/hnn/spacetime.h"
#include "../blackhole-simulator/hnn/constants.h"
#include "../blackhole-simulator/bhs.h"
#include <QtTest>

using namespace hnn;
using complex = std::complex<double>;

BiquaternionUnitTest::BiquaternionUnitTest()
{
}

void BiquaternionUnitTest::test_member()
{
    Biquaternion b0;
    QVERIFY(b0.re() == 0.0);
    QVERIFY(b0.hi() == 0.0);
    QVERIFY(b0.hj() == 0.0);
    QVERIFY(b0.hk() == 0.0);
    QVERIFY(b0.h() == 0.0);
    QVERIFY(b0.i() == 0.0);
    QVERIFY(b0.j() == 0.0);
    QVERIFY(b0.k() == 0.0);

    Biquaternion b1(1,2,3,4);
    double ir = b1.invariantReal();
    QVERIFY(ir == -28.0);
    double ii = b1.invariantImag();
    QVERIFY(ii == 0.0);
    complex norm = b1.norm();
    QVERIFY(norm == complex(-28.0, 0.0));
    Biquaternion b2(b1.biconjugated());
    QVERIFY(b2 == Biquaternion(1.0, 0.0, 0.0, -2.0, 0.0, -3.0, 0.0, -4.0));
    Biquaternion b3(b1.complexConjugated());
    QVERIFY(b3 == Biquaternion(1.0, 0.0, 0.0, -2.0, 0.0, -3.0, 0.0, -4.0));

    Biquaternion b4(1,2,3,4,5,6,7,8);
    complex norm4 = b4.norm();
    QVERIFY(norm4 == complex(-36.0, 200.0));
    Biquaternion b5(b4.biconjugated());
    QVERIFY(b5 == Biquaternion(1.0, 2.0, -3.0, -4.0, -5.0, -6.0, -7.0, -8.0));
    Biquaternion b6(b4.complexConjugated());
    QVERIFY(b6 == Biquaternion(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0));

    Biquaternion b7(9,10,11,12,13,14,15,16);

    // Important note for Biquaternions
    QVERIFY((b4 * b7).biconjugated() == b7.biconjugated() * b4.biconjugated());
    QVERIFY((b4 * b7).complexConjugated() == b4.complexConjugated() * b7.complexConjugated());
    QVERIFY(b4.biconjugated().complexConjugated() == b4.complexConjugated().biconjugated());
    QVERIFY(b4.norm() == (b4 * b4.biconjugated()).w());

    // Lorentz Transformation
    double theta = 1.234;
    Biquaternion b8(cos(theta), 0, sin(theta),0,0,0,0,0);
    complex c0 = b8.norm();
    qDebug() << c0;
    QVERIFY(fuzzyCompare(b8.norm(), complex(1.0, 0.0)));

    Biquaternion b9 = b1.lorentzTransformation(b8);
    qDebug() << b9;
    Biquaternion b10 = b8.lorentzTransformation(b1.re(), b1.hi(), b1.hj(), b1.hk());
    qDebug() << b10;
    QVERIFY(b9 == b10);

    Biquaternion b11(0.99,0.22,0.33,0.44);
    qDebug() << b11;
    Biquaternion b12 = b11.lorentzTransformation(b7);
    qDebug() << b12;
    Biquaternion b13 = b7.lorentzTransformation(b11.re(), b11.hi(), b11.hj(), b11.hk());
    qDebug() << b13;
    //QVERIFY(fuzzyCompare(b12, b13));
    QVERIFY(fuzzyCompare(b12.re(), b13.re()));
    QVERIFY(fuzzyCompare(b12.hi(), b13.hi()));
    QVERIFY(fuzzyCompare(b12.hj(), b13.hj()));
    QVERIFY(fuzzyCompare(b12.hk(), b13.hk()));

    Quaternion q0 = Quaternion::exp(11,-22,33);
    QVERIFY(q0.norm() == 1.0);
    Biquaternion b14(q0);
    QVERIFY(fuzzyCompare(b14.norm(), complex(1.0, 0.0)));

    Biquaternion b15 = b11.lorentzTransformation(b14);
    qDebug() << b15;
    Biquaternion b16 = b14.lorentzTransformation(b11.re(), b11.hi(), b11.hj(), b11.hk());
    qDebug() << b16;
    //QVERIFY(fuzzyCompare(b15, b16));
    QVERIFY(fuzzyCompare(b15.re(), b16.re()));
    QVERIFY(fuzzyCompare(b15.hi(), b16.hi()));
    QVERIFY(fuzzyCompare(b15.hj(), b16.hj()));
    QVERIFY(fuzzyCompare(b15.hk(), b16.hk()));

    qDebug() << b8;
    qDebug() << b14;
    qDebug() << b14 * b8;

    Biquaternion b17(cosh(1.5),-sinh(1.5),0,0);
    qDebug() << b17;
    qDebug() << b14 * b17;
    qDebug() << b14.norm();
    qDebug() << (b14 * b17).norm();

    Quaternion q1 = Quaternion::exp(44,-55,66);
    QVERIFY(q1.norm() == 1.0);
    Biquaternion b18(q0);
    QVERIFY(fuzzyCompare(b18.norm(), complex(1.0, 0.0)));

    qDebug() << b14 * b18;
    qDebug() << (b14 * b18).norm();
    qDebug() << b14 * b17 * b18;
    qDebug() << (b14 * b17 * b18).norm();
}

void BiquaternionUnitTest::test_LT()
{
    Vector3 direction(1., 2., 3.);
    direction.normalize();
    QVERIFY(direction.norm() == 1.);

    // v = c tanh( a )
    // a = atanh( v / c )
    double v0 = 1e+7;
    double rapidity0 = atanh(v0 / SPEED_OF_LIGHT);
    Spacetime g0 = Spacetime::exp(0.5 * rapidity0, direction);
    Biquaternion bg0;
    bg0.setSpacetimeReal(g0);
    qDebug() << "bg0:" << bg0;
    Quaternion ts0(SPEED_OF_LIGHT, 0., 0., 0.);
    qDebug() << ts0;
    //bg0.lorentzTransformation(ts0);
    //qDebug() << ts0;

    //for (int i = 0; i < 1000000; ++i)
    //{
    //    bg0.lorentzTransformation(ts0);
    //}
    //qDebug() << ts0;
    //QVERIFY(isinf(ts0.re()));
    //QVERIFY(isinf(ts0.i1()));
    //QVERIFY(isinf(ts0.i2()));
    //QVERIFY(isinf(ts0.i3()));
}
