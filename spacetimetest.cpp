#include "spacetimetest.h"
#include "../blackhole-simulator/hnn/spacetime.h"
#include "../blackhole-simulator/hnn/constants.h"
#include "../blackhole-simulator/bhs.h"
#include <QtTest>

using namespace hnn;
using complex = std::complex<double>;

SpacetimeTest::SpacetimeTest()
{

}

void SpacetimeTest::test_member()
{
    Spacetime st0(2., 3., 4., 5.);
    QVERIFY(st0.norm() == -46.);
    QVERIFY(st0.conjugated() == Spacetime(2., -3., -4., -5.));
    QVERIFY(fuzzyCompare(st0.abs(), complex(0., 6.782329983125268)));

    Vector3 direction1(1., 2., 3.);
    direction1.normalize();
    QVERIFY(direction1.norm() == 1.);

    // v = c tanh( a )
    // a = atanh( v / c )
    double v0 = 1e+7;
    double rapidity0 = atanh(v0 / SPEED_OF_LIGHT);
    Spacetime g0 = Spacetime::exp(0.5 * rapidity0, direction1);
    Spacetime ts0(SPEED_OF_LIGHT, 0., 0., 0.);
    ts0.lorentzTransformation(g0);
    qDebug() << "ts0:" << ts0;

    const double v1 = 0.9;
    Vector3 direction2(1., 0., 0.);
    double rapidity1 = atanh(v1);
    Spacetime g1 = Spacetime::exp(0.5 * rapidity1, direction2);
    qDebug() << "g1:" << g1;
    Spacetime ts1(SPEED_OF_LIGHT, 0., 0., 0.);
    ts1.lorentzTransformation(g1);
    qDebug() << "ts1:" << ts1;
    qDebug() << "SPEED_OF_LIGHT * " << v1 << ":" << SPEED_OF_LIGHT * v1;
    qDebug() << "speed:" << - ts1.x() * (SPEED_OF_LIGHT / ts1.w());
    QVERIFY(fuzzyCompare(SPEED_OF_LIGHT * v1, - ts1.x() * (SPEED_OF_LIGHT / ts1.w())));
}
