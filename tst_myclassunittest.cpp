#include <QtTest>

#include "vector3unittest.h"
#include "quaternionunittest.h"
#include "octonionunittest.h"
#include "biquaternionunittest.h"
#include "spacetimetest.h"
#include "cliffordunittest.h"

using namespace hnn;

class MyClassUnitTest : public QObject
{
    Q_OBJECT

    static constexpr double PI = 3.141592653589793;

public:
    MyClassUnitTest();
    ~MyClassUnitTest();

private slots:
    void test_vector3()
    {
        Vector3UnitTest ut;
        ut.test_constructor();
        ut.test_operator();
        ut.test_func();
        ut.test_constexpr();
    }

    void test_quaternion()
    {
        QuaternionUnitTest ut;
        ut.test_member();
        ut.test_constructor();
        ut.test_set();
        ut.test_operator();
        ut.test_zero();
        ut.test_ln();
        ut.test_norm();
    }

    void test_octonion()
    {
        OctonionUnitTest ut;
        ut.test_member();
    }

    void test_biquaternion()
    {
        BiquaternionUnitTest ut;
        ut.test_member();
        ut.test_LT();
    }

    void test_spacetime()
    {
        SpacetimeTest st;
        st.test_member();
    }

    void test_clifford()
    {
        CliffordUnitTest ut;
        ut.test_constructor();
    }
};

MyClassUnitTest::MyClassUnitTest()
{
}

MyClassUnitTest::~MyClassUnitTest()
{
}

QTEST_APPLESS_MAIN(MyClassUnitTest)

#include "tst_myclassunittest.moc"
