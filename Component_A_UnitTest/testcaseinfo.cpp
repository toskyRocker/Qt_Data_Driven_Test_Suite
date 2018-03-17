#include "testcaseinfo.h"

using namespace UnitTestNamespace;

TestCaseInfo::TestCaseInfo()
{

}

TestCaseInfo::~TestCaseInfo()
{

}

QString TestCaseInfo::getTestCaseID() const
{
    return testCaseID;
}

void TestCaseInfo::setTestCaseID(const QString &value)
{
    testCaseID = value;
}

QHash<QString, QString> TestCaseInfo::getInputData() const
{
    return inputData;
}


QHash<QString, QString> TestCaseInfo::getVerificationData() const
{
    return verificationData;
}


void TestCaseInfo::insertInputDataElement(QString key, QString value)
{
    inputData.insert(key, value);
}

void TestCaseInfo::insertVerificationDataElement(QString key, QString value)
{
    verificationData.insert(key, value);
}
