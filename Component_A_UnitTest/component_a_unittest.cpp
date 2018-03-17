#include "component_a_unittest.h"
#include <QSharedData>

class Component_A_UnitTest_Data: public QSharedData
{
public:
    Component_A* cmpA = nullptr;
    JsonFileParser* parser = nullptr;

    ~Component_A_UnitTest_Data()
    {
        if(cmpA)
            delete cmpA;

        if(parser)
            delete parser;
    }
};

Component_A_UnitTest::Component_A_UnitTest()
{
    // Never forget to instantiate your data container
    testData = new Component_A_UnitTest_Data();

    // Instantiating the parser needed to read the configuration file
    testData->parser = new JsonFileParser();
}

Component_A_UnitTest::~Component_A_UnitTest()
{

}

bool Component_A_UnitTest::parseConfigurationFile(QString configFileName)
{
    return testData->parser->parseConfigurationFile(configFileName);
}

void Component_A_UnitTest::initTestCase()
{
    // Instantiating my Component under test
    testData->cmpA = new Component_A();
}

void Component_A_UnitTest::cleanupTestCase()
{

}

void Component_A_UnitTest::init()
{

}

void Component_A_UnitTest::cleanup()
{

}

void Component_A_UnitTest::testProcedurePow()
{
    // Fetching all the needed data to run the test from the table
    // defined in testProcedure_pow_data()
    // Fetching the information by providing the key
    QFETCH(QString, test_case_id);
    QFETCH(QString, base);
    QFETCH(QString, exp);
    QFETCH(QString, expected_result);

    qDebug() << "Component_A_UnitTest::testProcedurePow - " << test_case_id;

    // Converting the input data to the needed type
    int baseValue = base.toInt();
    int exponentValue = exp.toInt();
    int expectedValue = expected_result.toInt();

    // Performing the needed operation that need to be tested
    int actualValue = testData->cmpA->doPow(baseValue, exponentValue);

    // Verificaiton Step
    QCOMPARE(actualValue, expectedValue);

}

void Component_A_UnitTest::testProcedurePow_data()
{
    // Populating Columns' headers
    QTest::addColumn<QString>(TEST_CASE_ID);
    QTest::addColumn<QString>(BASE);
    QTest::addColumn<QString>(EXP);
    QTest::addColumn<QString>(EXPECTED_RESULT);

    // Populating each row i.e. test
    for(TestCaseInfo testCaseInfo : testData->parser->getTestCaseInfoList())
    {
        // Doesn't accept QString. It needs to be converted to std String
        QString testCaseID = testCaseInfo.getTestCaseID();
        const char* testCaseID_std = testCaseID.toStdString().c_str();
        QString base = testCaseInfo.getInputData().value(BASE);
        QString exp = testCaseInfo.getInputData().value(EXP);
        QString expectedResult = testCaseInfo.getVerificationData().value(EXPECTED_RESULT);

        QTest::newRow(testCaseID_std)
                << testCaseID
                << base
                << exp
                << expectedResult;
    }
}
