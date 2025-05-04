#include "../blackhole-simulator/hnn/clifford13.h"
#include "../blackhole-simulator/hnn/clifford31.h"

#include "cliffordunittest.h"
#include <QtTest>

CliffordUnitTest::CliffordUnitTest()
{

}

void CliffordUnitTest::test_constructor()
{
    qDebug() << Clifford13::to_table_string();
    qDebug() << Clifford13::to_table_string_tex1();
    qDebug() << Clifford13::to_table_string_tex2();
    qDebug() << Clifford13::to_table_string_tex();
    qDebug() << Clifford31::to_table_string_tex();
}
