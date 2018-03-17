/**
 *
 * @file jsonfileparser.h
 * @author Andrea Toscano
 * @version 1.0
 *
 * @brief It reads a configuration file and stores
 * the information needed for running the Unit Test
 * @section DESCRIPTION
 *
 * The main purpose of this class is to read the
 * provided json configuration file and storing
 * all the extracted information in its data structure
 * implemented as a list of TestCaseInfo.
 *
 *
**/

#ifndef JSONFILEPARSER_H
#define JSONFILEPARSER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QList>
#include <QDebug>

#include "testcaseinfo.h"
#include "component_a_unittest_definitions.h"

namespace UnitTestNamespace
{

class JsonFileParser
{
public:
    JsonFileParser();
    ~JsonFileParser();
    bool parseConfigurationFile(QString inFileName);

    QString getFileName() const;
    void setFileName(const QString &value);

    QList<TestCaseInfo> getTestCaseInfoList() const;

private:

    bool readMainObject(QJsonObject &jsonObj);
    bool parseMainObject(QJsonObject &jsonObj);


    QString fileName;
    QList<TestCaseInfo> testCaseInfoList;
};

}

#endif // JSONFILEPARSER_H
