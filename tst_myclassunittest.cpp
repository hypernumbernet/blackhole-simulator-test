#include <QtTest>

#include <QQuaternion>
#include "../blackhole-simulator/hnn/quaternion.h"
#include "vector3unittest.h"

using namespace hnn;

class MyClassUnitTest : public QObject
{
    Q_OBJECT

    static constexpr double PI = 3.141592653589793;

public:
    MyClassUnitTest();
    ~MyClassUnitTest();

private slots:
    void test_member();
    void test_array();
    void test_constructor();
    void test_set();
    void test_operator();
    void test_zero();
    void test_ln();
    void test_vector3();
};

MyClassUnitTest::MyClassUnitTest()
{
}

MyClassUnitTest::~MyClassUnitTest()
{
}

void MyClassUnitTest::test_member()
{
    Quaternion<float> q;

    q.i0 = 10.0f;
    q.i1 = 11.0f;
    q.i2 = 12.0f;
    q.i3 = 13.0f;

    QVERIFY(q.i0 == 10.0f);
    QCOMPARE(q.i0, 10.0f);

    QVERIFY(q.i1 == 11.0f);
    QVERIFY(q.i2 == 12.0f);
    QVERIFY(q.i3 == 13.0f);

    Quaternion<double> d;

    d.i0 = 10.0;
    d.i1 = 11.0;
    d.i2 = 12.0;
    d.i3 = 13.0;

    QVERIFY(d.i0 == 10.0);
    QVERIFY(d.i1 == 11.0);
    QVERIFY(d.i2 == 12.0);
    QVERIFY(d.i3 == 13.0);
}

void MyClassUnitTest::test_array()
{
    Quaternion<double> d;

    d.array[0] = 20.0;
    d.array[1] = 21.0;
    d.array[2] = 22.0;
    d.array[3] = 23.0;

    QVERIFY(d.array[0] == 20.0);
    QVERIFY(d.array[1] == 21.0);
    QVERIFY(d.array[2] == 22.0);
    QVERIFY(d.array[3] == 23.0);
}

void MyClassUnitTest::test_constructor()
{
    Quaternion<double> q1;
    q1.set(4,3,2,1);
    QVERIFY(q1.i0 == 4.0);
    QVERIFY(q1.i1 == 3.0);
    QVERIFY(q1.i2 == 2.0);
    QVERIFY(q1.i3 == 1.0);

    Quaternion<double> q2(1,2,3,4);
    QVERIFY(q2.i0 == 1.0);
    QVERIFY(q2.i1 == 2.0);
    QVERIFY(q2.i2 == 3.0);
    QVERIFY(q2.i3 == 4.0);

    Quaternion<double> q3(q2);
    QVERIFY(q3.i0 == 1.0);
    QVERIFY(q3.i1 == 2.0);
    QVERIFY(q3.i2 == 3.0);
    QVERIFY(q3.i3 == 4.0);

    auto q4 = q2;
    QVERIFY(q4.i0 == 1.0);
    QVERIFY(q4.i1 == 2.0);
    QVERIFY(q4.i2 == 3.0);
    QVERIFY(q4.i3 == 4.0);
}

void MyClassUnitTest::test_set()
{
    Quaternion<double> q1;

    q1.set(11,22,33,44);

    QVERIFY(q1.i0 == 11.0);
    QVERIFY(q1.i1 == 22.0);
    QVERIFY(q1.i2 == 33.0);
    QVERIFY(q1.i3 == 44.0);
}

void MyClassUnitTest::test_operator()
{
    Quaternion<double> q1(11,22,33,44);
    Quaternion<double> q2(11,22,33,44);
    Quaternion<double> q3;

    q3 = q1 + q2;
    QVERIFY(q3.i0 == 22.0);
    QVERIFY(q3.i1 == 44.0);
    QVERIFY(q3.i2 == 66.0);
    QVERIFY(q3.i3 == 88.0);

    Quaternion<double> q4;

    q2 = {1,2,3,4};

    q4 = q1 - q2;
    QVERIFY(q4.i0 == 10.0);
    QVERIFY(q4.i1 == 20.0);
    QVERIFY(q4.i2 == 30.0);
    QVERIFY(q4.i3 == 40.0);

    QQuaternion qq1(11,22,33,44);
    QQuaternion qq2(55,66,77,88);
    QQuaternion qq3 = qq1 * qq2;

    Quaternion<float> mq1(11,22,33,44);
    Quaternion<float> mq2(55,66,77,88);
    Quaternion<float> mq3 = mq1 * mq2;

    QVERIFY(qq3.scalar() == mq3.i0);
    QVERIFY(qq3.x() == mq3.i1);
    QVERIFY(qq3.y() == mq3.i2);
    QVERIFY(qq3.z() == mq3.i3);

    Quaternion<double> q5(1,1,1,1);
    auto q6 = q5 * 3.0;
    QVERIFY(q6.i0 == 3.0);
    QVERIFY(q6.i1 == 3.0);
    QVERIFY(q6.i2 == 3.0);
    QVERIFY(q6.i3 == 3.0);

    Quaternion<double> q7(10,10,10,10);
    auto q8 = 3.0 * q7;
    QVERIFY(q8.i0 == 30.0);
    QVERIFY(q8.i1 == 30.0);
    QVERIFY(q8.i2 == 30.0);
    QVERIFY(q8.i3 == 30.0);

    //Quaternion<Quaternion<double>> qqd1;

}

void MyClassUnitTest::test_zero()
{
    auto q0 = Quaternion<double>::Zero;
    QVERIFY(q0.i0 == 0.0);
    QVERIFY(q0.i1 == 0.0);
    QVERIFY(q0.i2 == 0.0);
    QVERIFY(q0.i3 == 0.0);

    auto q1 = Quaternion<double>::Identity;
    QVERIFY(q1.i0 == 1.0);
    QVERIFY(q1.i1 == 0.0);
    QVERIFY(q1.i2 == 0.0);
    QVERIFY(q1.i3 == 0.0);
}

void MyClassUnitTest::test_ln()
{
    Quaternion<double> q1(0,1,0,0);
    auto v1 = q1.LnV3Half();
    QVERIFY(v1.x() > (PI / 2.0 - 0.001) && v1.x() < (PI / 2.0 + 0.001));

    Quaternion<double> q2(1,0,1,0);
    q2.Normalize();
    auto v2 = q2.LnV3Half();
    QVERIFY(v2.x() == 0.0);
    QVERIFY(v2.y() > 0.0 && v2.y() < PI / 2.0);
    QVERIFY(v2.z() == 0.0);

    Quaternion<double> q3(-1,0,0,1);
    q3.Normalize();
    auto v3 = q3.LnV3Half();
    QVERIFY(v3.x() == 0.0);
    QVERIFY(v3.y() == 0.0);
    QVERIFY(v3.z() < 0.0 && v3.z() > -PI / 2.0);

    Quaternion<double> q4(-1,0,0,-1);
    q4.Normalize();
    auto v4 = q4.LnV3Half();
    QVERIFY(v4.x() == 0.0);
    QVERIFY(v4.y() == 0.0);
    QVERIFY(v4.z() > 0.0 && v4.z() < PI / 2.0);

    Quaternion<double> q5(1,0,0,-1);
    q5.Normalize();
    auto v5 = q5.LnV3Half();
    QVERIFY(v5.x() == 0.0);
    QVERIFY(v5.y() == 0.0);
    QVERIFY(v5.z() < 0.0 && v5.z() > -PI / 2.0);

}

void MyClassUnitTest::test_vector3()
{
    Vector3UnitTest ut;
    ut.test_constructor();
    ut.test_operator();
    ut.test_func();
    ut.test_constexpr();
}

QTEST_APPLESS_MAIN(MyClassUnitTest)

#include "tst_myclassunittest.moc"
