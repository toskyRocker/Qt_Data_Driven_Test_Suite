/**
 *
 * @file testcaseinfo.h
 * @author Andrea Toscano
 * @version 1.0
 *
 * @brief It stores all the information belonging
 * to a single Test Case
 * @section DESCRIPTION
 *
 * Each Test Case is represented by:
 * - Its Test Case ID
 * - Input Data needed to run the test
 * - Verification Data needed to compare the actual
 *   to the expected result
 *
 *
**/

#ifndef TESTCASEINFO_H
#define TESTCASEINFO_H

#include <QString>
#include <QHash>

namespace UnitTestNamespace
{
class TestCaseInfo
{
public:
    TestCaseInfo();
    virtual ~TestCaseInfo();

    QString getTestCaseID() const;
    void setTestCaseID(const QString &value);

    QHash<QString, QString> getInputData() const;
    QHash<QString, QString> getVerificationData() const;

    /**
     * @brief insertInputDataElement Called in case a new Input Data pair
     * has to be inserted in the Input Data structure.
     * @param key String representing the Label of the input data.
     * @param value String representing the value input data.
     */
    void insertInputDataElement(QString key, QString value);

    /**
     * @brief insertVerificationDataElement Called in case a new Verification
     * Data pair has to be inserted in the Verification Data structure.
     * @param key String representing the Label of the verification data.
     * @param value String representing the value of the verification data.
     */
    void insertVerificationDataElement(QString key, QString value);

private:
    QString testCaseID;
    QHash<QString, QString> inputData;
    QHash<QString, QString> verificationData;

};
}
#endif // TESTCASEINFO_H
