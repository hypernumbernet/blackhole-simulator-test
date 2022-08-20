#include "quaternionunittest.h"

QuaternionUnitTest::QuaternionUnitTest()
{
}

void QuaternionUnitTest::test_member()
{
    Quaternion<float> q;

    q.setRe(10.0f);
    q.setI1(11.0f);
    q.setI2(12.0f);
    q.setI3(13.0f);

    QVERIFY(q.re() == 10.0f);
    QCOMPARE(q.re(), 10.0f);

    QVERIFY(q.i1() == 11.0f);
    QVERIFY(q.i2() == 12.0f);
    QVERIFY(q.i3() == 13.0f);

    Quaternion<double> d;

    d.setRe(10.01);
    d.setI1(11.02);
    d.setI2(12.03);
    d.setI3(13.04);

    QVERIFY(d.re() == 10.01);
    QVERIFY(d.i1() == 11.02);
    QVERIFY(d.i2() == 12.03);
    QVERIFY(d.i3() == 13.04);
}

void QuaternionUnitTest::test_constructor()
{
    Quaternion<double> q1;
    q1.set(4,3,2,1);
    QVERIFY(q1.re() == 4.0);
    QVERIFY(q1.i1() == 3.0);
    QVERIFY(q1.i2() == 2.0);
    QVERIFY(q1.i3() == 1.0);

    Quaternion<double> q2(1,2,3,4);
    QVERIFY(q2.re() == 1.0);
    QVERIFY(q2.i1() == 2.0);
    QVERIFY(q2.i2() == 3.0);
    QVERIFY(q2.i3() == 4.0);

    Quaternion<double> q3(q2);
    QVERIFY(q3.re() == 1.0);
    QVERIFY(q3.i1() == 2.0);
    QVERIFY(q3.i2() == 3.0);
    QVERIFY(q3.i3() == 4.0);

    auto q4 = q2;
    QVERIFY(q4.re() == 1.0);
    QVERIFY(q4.i1() == 2.0);
    QVERIFY(q4.i2() == 3.0);
    QVERIFY(q4.i3() == 4.0);

    double a5 = 55.55;
    Quaternion<double> q5(a5);
    QVERIFY(q5.re() == 55.55);
    QVERIFY(q5.i1() == 0.0);
    QVERIFY(q5.i2() == 0.0);
    QVERIFY(q5.i3() == 0.0);

    Vector3<double> v6(9,6,3);
    Quaternion<double> q6(v6);
    QVERIFY(q6.re() == 0.0);
    QVERIFY(q6.i1() == 9.0);
    QVERIFY(q6.i2() == 6.0);
    QVERIFY(q6.i3() == 3.0);

    double a7[20] = {};
    a7[6] = 5.5;
    a7[7] = 3.3;
    a7[8] = 8.8;
    a7[9] = 2.2;
    Quaternion<double> q7(a7, 6);
    QVERIFY(q7.re() == 5.5);
    QVERIFY(q7.i1() == 3.3);
    QVERIFY(q7.i2() == 8.8);
    QVERIFY(q7.i3() == 2.2);
}

void QuaternionUnitTest::test_set()
{
    Quaternion<double> q1;
    q1.set(11,22,33,44);
    QVERIFY(q1.re() == 11.0);
    QVERIFY(q1.i1() == 22.0);
    QVERIFY(q1.i2() == 33.0);
    QVERIFY(q1.i3() == 44.0);

    double a2[] = {2.2, 3.3, 4.4, 5.5};
    Quaternion<double> q2;
    q2.set(a2);
    QVERIFY(q2.re() == 2.2);
    QVERIFY(q2.i1() == 3.3);
    QVERIFY(q2.i2() == 4.4);
    QVERIFY(q2.i3() == 5.5);

    double a3[20];
    a3[10] = 5.5;
    a3[11] = 3.3;
    a3[12] = 8.8;
    a3[13] = 2.2;
    Quaternion<double> q3;
    q3.set(a3, 10);
    QVERIFY(q3.re() == 5.5);
    QVERIFY(q3.i1() == 3.3);
    QVERIFY(q3.i2() == 8.8);
    QVERIFY(q3.i3() == 2.2);
}

void QuaternionUnitTest::test_operator()
{
    Quaternion<double> q1(11,22,33,44);
    Quaternion<double> q2(11,22,33,44);
    Quaternion<double> q3;

    q3 = q1 + q2;
    QVERIFY(q3.re() == 22.0);
    QVERIFY(q3.i1() == 44.0);
    QVERIFY(q3.i2() == 66.0);
    QVERIFY(q3.i3() == 88.0);

    Quaternion<double> q4;

    q2 = {1,2,3,4};

    q4 = q1 - q2;
    QVERIFY(q4.re() == 10.0);
    QVERIFY(q4.i1() == 20.0);
    QVERIFY(q4.i2() == 30.0);
    QVERIFY(q4.i3() == 40.0);

    QQuaternion qq1(11,22,33,44);
    QQuaternion qq2(55,66,77,88);
    QQuaternion qq3 = qq1 * qq2;

    Quaternion<float> mq1(11,22,33,44);
    Quaternion<float> mq2(55,66,77,88);
    Quaternion<float> mq3 = mq1 * mq2;

    QVERIFY(qq3.scalar() == mq3.re());
    QVERIFY(qq3.x() == mq3.i1());
    QVERIFY(qq3.y() == mq3.i2());
    QVERIFY(qq3.z() == mq3.i3());

    Quaternion<double> q5(1,1,1,1);
    auto q6 = q5 * 3.0;
    QVERIFY(q6.re() == 3.0);
    QVERIFY(q6.i1() == 3.0);
    QVERIFY(q6.i2() == 3.0);
    QVERIFY(q6.i3() == 3.0);

    Quaternion<double> q7(10,10,10,10);
    auto q8 = 3.0 * q7;
    QVERIFY(q8.re() == 30.0);
    QVERIFY(q8.i1() == 30.0);
    QVERIFY(q8.i2() == 30.0);
    QVERIFY(q8.i3() == 30.0);

    Quaternion<double> mq9a(11,22,33,44);
    Quaternion<double> mq9b(55,66,77,88);
    auto mq9c = mq9a / mq9b;
    auto mq9d = mq9c * mq9b;
    QVERIFY(fabs(mq9d.re() - 11.0) < 1e-5);
    QVERIFY(fabs(mq9d.i1() - 22.0) < 1e-5);
    QVERIFY(fabs(mq9d.i2() - 33.0) < 1e-5);
    QVERIFY(fabs(mq9d.i3() - 44.0) < 1e-5);
    QVERIFY(mq9d.fuzzyCompare({11,22,33,44}));

    Quaternion<double> q10a(9,6,2,7);
    Quaternion<double> q10b(5,6,7,8);
    q10a /= q10b;
    q10a *= q10b;
    QVERIFY(q10a.fuzzyCompare({9,6,2,7}));

    Quaternion<float> q11a(19,16,12,17);
    Quaternion<float> q11b(15,16,17,18);
    q11a /= q11b;
    q11a *= q11b;
    QVERIFY(q11a.fuzzyCompare({19,16,12,17}));
}

void QuaternionUnitTest::test_zero()
{
    auto q0 = Quaternion<double>::zero();
    QVERIFY(q0.re() == 0.0);
    QVERIFY(q0.i1() == 0.0);
    QVERIFY(q0.i2() == 0.0);
    QVERIFY(q0.i3() == 0.0);

    auto q1 = Quaternion<double>::identity();
    QVERIFY(q1.re() == 1.0);
    QVERIFY(q1.i1() == 0.0);
    QVERIFY(q1.i2() == 0.0);
    QVERIFY(q1.i3() == 0.0);
}

void QuaternionUnitTest::test_ln()
{
    Quaternion<double> q1(0,1,0,0);
    auto v1 = q1.lnV3Half();
    QVERIFY(v1.x() > (PI / 2.0 - 0.001) && v1.x() < (PI / 2.0 + 0.001));

    Quaternion<double> q2(1,0,1,0);
    q2.normalize();
    auto v2 = q2.lnV3Half();
    QVERIFY(v2.x() == 0.0);
    QVERIFY(v2.y() > 0.0 && v2.y() < PI / 2.0);
    QVERIFY(v2.z() == 0.0);

    Quaternion<double> q3(-1,0,0,1);
    q3.normalize();
    auto v3 = q3.lnV3Half();
    QVERIFY(v3.x() == 0.0);
    QVERIFY(v3.y() == 0.0);
    QVERIFY(v3.z() < 0.0 && v3.z() > -PI / 2.0);

    Quaternion<double> q4(-1,0,0,-1);
    q4.normalize();
    auto v4 = q4.lnV3Half();
    QVERIFY(v4.x() == 0.0);
    QVERIFY(v4.y() == 0.0);
    QVERIFY(v4.z() > 0.0 && v4.z() < PI / 2.0);

    Quaternion<double> q5(1,0,0,-1);
    q5.normalize();
    auto v5 = q5.lnV3Half();
    QVERIFY(v5.x() == 0.0);
    QVERIFY(v5.y() == 0.0);
    QVERIFY(v5.z() < 0.0 && v5.z() > -PI / 2.0);
}

void QuaternionUnitTest::test_norm()
{
    Quaternion<double> q1(1,2,3,4);
    double n1 = q1.norm();
    QVERIFY(n1 == 30.0);

    Quaternion<double> q2(1,2,3,4);
    double n2 = q2.abs();
    QVERIFY(n2 == sqrt(30.0));

    Quaternion<double> q3(1,2,3,4);
    q3.normalize();
    QVERIFY(fuzzyCompare(q3.norm(), 1.0));

}
