#include <QtTest>

#include "../blackhole-simulator/quaternion.h"

class MyClassUnitTest : public QObject
{
    Q_OBJECT

public:
    MyClassUnitTest();
    ~MyClassUnitTest();

private slots:
    void test_case1();

};

MyClassUnitTest::MyClassUnitTest()
{

}

MyClassUnitTest::~MyClassUnitTest()
{

}

void MyClassUnitTest::test_case1()
{
    bhs::Quaternion<float> q;

    q.i0 = 1;

}

QTEST_APPLESS_MAIN(MyClassUnitTest)

#include "tst_myclassunittest.moc"
