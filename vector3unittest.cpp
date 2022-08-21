#include "vector3unittest.h"

Vector3UnitTest::Vector3UnitTest()
{

}

void Vector3UnitTest::test_constructor()
{
    Vector3 v1;
    v1.setX(1);
    v1.setY(2);
    v1.setZ(3);
    QVERIFY(v1.x() == 1.0f);
    QVERIFY(v1.y() == 2.0f);
    QVERIFY(v1.z() == 3.0f);

    Vector3 v2(4,5,6);
    QVERIFY(v2.x() == 4.0);
    QVERIFY(v2.y() == 5.0);
    QVERIFY(v2.z() == 6.0);

    Vector3 v3;
    v3.set(7,8,9);
    QVERIFY(v3.x() == 7.0);
    QVERIFY(v3.y() == 8.0);
    QVERIFY(v3.z() == 9.0);

    double a4[] = {1,2,3};
    Vector3 v4(a4);
    QVERIFY(v4.x() == 1.0);
    QVERIFY(v4.y() == 2.0);
    QVERIFY(v4.z() == 3.0);

    double a5[20] = {};
    QVERIFY(a5[0] == 0.0);
    QVERIFY(a5[19] == 0.0);
    a5[6] = 4.4;
    a5[7] = 5.5;
    a5[8] = 6.6;
    Vector3 v5(a5, 6);
    QVERIFY(v5.x() == 4.4);
    QVERIFY(v5.y() == 5.5);
    QVERIFY(v5.z() == 6.6);

}

void Vector3UnitTest::test_operator()
{
    const Vector3 v1(1,2,3);
    const Vector3 v2(4,5,6);
    auto v3 = v1 + v2;
    QVERIFY(v3.x() == 5.0);
    QVERIFY(v3.y() == 7.0);
    QVERIFY(v3.z() == 9.0);

    auto v4 = v2 - v1;
    QVERIFY(v4.x() == 3.0);
    QVERIFY(v4.y() == 3.0);
    QVERIFY(v4.z() == 3.0);

    auto v5 = +v1;
    QVERIFY(v5.x() == 1.0);
    QVERIFY(v5.y() == 2.0);
    QVERIFY(v5.z() == 3.0);

    auto v6 = -v1;
    QVERIFY(v6.x() == -1.0);
    QVERIFY(v6.y() == -2.0);
    QVERIFY(v6.z() == -3.0);

    double d7 = 3.0;
    auto v7 = v1 * d7;
    QVERIFY(v7.x() == 3.0);
    QVERIFY(v7.y() == 6.0);
    QVERIFY(v7.z() == 9.0);

    Vector3 v8(1,2,3);
    v8 += v1;
    QVERIFY(v8.x() == 2.0);
    QVERIFY(v8.y() == 4.0);
    QVERIFY(v8.z() == 6.0);

    Vector3 v9(1,2,3);
    v9 -= v2;
    QVERIFY(v9.x() == -3.0);
    QVERIFY(v9.y() == -3.0);
    QVERIFY(v9.z() == -3.0);

    Vector3 v10a(1,2,3);
    Vector3 v10b(4,5,6);
    Vector3 v10c(7,8,9);
    v10c += v10a += v10b;
    QVERIFY(v10c.x() == 12.0);
    QVERIFY(v10c.y() == 15.0);
    QVERIFY(v10c.z() == 18.0);

    Vector3 v11a(1,2,3);
    Vector3 v11b(4,5,6);
    Vector3 v11c(7,8,9);
    v11c -= v11a -= v11b;
    QVERIFY(v11c.x() == 10.0);
    QVERIFY(v11c.y() == 11.0);
    QVERIFY(v11c.z() == 12.0);

    Vector3 v12a(1,2,3);
    Vector3 v12b(4,5,6);
    Vector3 v12c(7,8,9);
    (v12c += v12a) = v12b;
    QVERIFY(v12c.x() == 4.0);
    QVERIFY(v12c.y() == 5.0);
    QVERIFY(v12c.z() == 6.0);

    Vector3 v13a(1,2,3);
    Vector3 v13b(4,5,6);
    Vector3 v13c(7,8,9);
    (v13c += v13a) = v13b;
    QVERIFY(v13c.x() == 4.0);
    QVERIFY(v13c.y() == 5.0);
    QVERIFY(v13c.z() == 6.0);

    Vector3 v14(1,2,3);
    double d14 = 4.0;
    auto v14a = v14 * d14;
    QVERIFY(v14a.x() == 4.0);
    QVERIFY(v14a.y() == 8.0);
    QVERIFY(v14a.z() == 12.0);

    Vector3 v15(4,5,6);
    double d15 = 6.0;
    auto v15a = d15 * v15;
    QVERIFY(v15a.x() == 24.0);
    QVERIFY(v15a.y() == 30.0);
    QVERIFY(v15a.z() == 36.0);

    Vector3 v16(1,2,3);
    double d16 = 4.0;
    v16 *= d16;
    QVERIFY(v16.x() == 4.0);
    QVERIFY(v16.y() == 8.0);
    QVERIFY(v16.z() == 12.0);

    Vector3 v17(4,2,8);
    double d17 = 2.0;
    v17 /= d17;
    QVERIFY(v17.x() == 2.0);
    QVERIFY(v17.y() == 1.0);
    QVERIFY(v17.z() == 4.0);

    const Vector3 v18a(9,-2,8);
    const Vector3 v18b(9,-2,8);
    QVERIFY(v18a == v18b);

    const Vector3 v19a(1,-2,8);
    const Vector3 v19b(9,-2,8);
    QVERIFY(v19a != v19b);
}

void Vector3UnitTest::test_func()
{
    const Vector3 v1(1,-2,3);
    QVERIFY(v1.norm() == 14.0);

    const Vector3 v2(1,-2,3);
    QVERIFY(v2.abs() == sqrt(14.0));

    Vector3 v3(1,-2,3);
    v3.normalize();
    QVERIFY(v3.x() == 1.0 / sqrt(14.0));
    QVERIFY(v3.y() == -2.0 / sqrt(14.0));
    QVERIFY(v3.z() == 3.0 / sqrt(14.0));

    Vector3 v4(1,-2,3);
    auto v4a = v4.normalized();
    QVERIFY(v4a.x() == 1.0 / sqrt(14.0));
    QVERIFY(v4a.y() == -2.0 / sqrt(14.0));
    QVERIFY(v4a.z() == 3.0 / sqrt(14.0));

    Vector3 v5a(1,-2,3);
    Vector3 v5b(-4,5,6);
    auto v5c = v5a.dot(v5b);
    QVERIFY(v5c == 4.0);

    Vector3 v6(0,0,0);
    auto v6a = v6.normalized();
    QVERIFY(v6a.x() == 0.0);
    QVERIFY(v6a.y() == 0.0);
    QVERIFY(v6a.z() == 0.0);

    Vector3 v7a(3,-4,5);
    Vector3 v7b(6,7,-8);
    auto d7 = v7a.distance(v7b);
    QVERIFY(d7 == sqrt(299.0));

    Vector3 v8a(3,-4,1);
    Vector3 v8b(3,7,-5);
    auto v8c = v8a.cross(v8b);
    QVERIFY(v8c.x() == 13.0);
    QVERIFY(v8c.y() == 18.0);
    QVERIFY(v8c.z() == 33.0);
}

void Vector3UnitTest::test_constexpr()
{
    Vector3 v1(ce01());
    QVERIFY(v1.x() == 0.6);
    QVERIFY(v1.y() == 3.0);
    QVERIFY(v1.z() == 2.0);

    auto v2 = ce02();
    QVERIFY(v2.x() == 1.0);
    QVERIFY(v2.y() == 2.0);
    QVERIFY(v2.z() == 3.0);

    auto v3 = ce03();
    QVERIFY(v3.x() == 5.0);
    QVERIFY(v3.y() == 7.0);
    QVERIFY(v3.z() == 9.0);

    Vector3 v4(0,0,0);
    QVERIFY(v4.x() == 0.0);
    QVERIFY(v4.y() == 0.0);
    QVERIFY(v4.z() == 0.0);

    auto v5 = ce05({3,4,1});
    QVERIFY(v5.x() == 6.0);
    QVERIFY(v5.y() == 8.0);
    QVERIFY(v5.z() == 2.0);

}
