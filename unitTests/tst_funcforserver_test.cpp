#include <QtTest>
#include "../echoServer/functions.h"
// add necessary includes here

class FuncForServer_Test : public QObject
{
    Q_OBJECT

public:
    FuncForServer_Test();
    ~FuncForServer_Test();

private slots:
    void test_cypher();
};

FuncForServer_Test::FuncForServer_Test()
{
}

FuncForServer_Test::~FuncForServer_Test()
{

}

void FuncForServer_Test::test_cypher()
{
    QString test_case1=   "13 _sd1fgers2, 5hsa";
    QString test_case1_ans = "l q<str  ?9-Bu n";
    QCOMPARE(caesarCipher(test_case1, 13), test_case1_ans);
    QString test_case2=    "1 Hello, World!";
    QString test_case2_ans = "Ifmmp-!Xpsme";
    QCOMPARE(caesarCipher(test_case2, 1), test_case2_ans);
    QString test_case3=    "2 Test message.";
    QString test_case3_ans = "Vguv!nhvvdjh/";
    QCOMPARE(caesarCipher(test_case3, 2), test_case3_ans);
}

QTEST_APPLESS_MAIN(FuncForServer_Test)
#include "tst_funcforserver_test.moc"
