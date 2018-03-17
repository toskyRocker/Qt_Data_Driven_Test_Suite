#include "jsonfileparser.h"

using namespace UnitTestNamespace;

JsonFileParser::JsonFileParser()
{

}

JsonFileParser::~JsonFileParser()
{

}

bool JsonFileParser::parseConfigurationFile(QString inFileName)
{
    bool parseOk = true;

    // Checking that the file name is not empty
    if(inFileName.isEmpty())
    {
        qDebug() << "JsonFileParser::ParseConfigurationFile - Empty Filename";
        return false;
    }

    fileName = inFileName;

    QJsonObject mainObj;

    // Extracting the main Json Object from the file
    parseOk &= readMainObject(mainObj);
    if(!parseOk)
        return parseOk;

    // Parsing the Json Object and saving data in TestCaseInfo List
    parseOk &= parseMainObject(mainObj);

    return parseOk;
}

bool JsonFileParser::readMainObject(QJsonObject& jsonObject)
{
    QFile file;

    file.setFileName(fileName);
    if(!file.exists())
    {
        qDebug() << "JsonFileParser::readMainObject - File doesn't exist:" << fileName;
        return false;
    }

    QByteArray jsonData;

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "JsonFileParser::readMainObject - Cannot open the file:" << fileName;
        return false;
    }

    jsonData = file.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);
    jsonObject = jsonDoc.object();

    if(jsonObject.isEmpty())
    {
        qDebug() << "JsonFileParser::readMainObject - Json File is empty: " << fileName;
        return false;
    }

    if (jsonError.error != QJsonParseError::NoError)
    {
        // Json file could not be parsed correctly
        qDebug() << "JsonFileParser::readMainObject - File not consistent:" << fileName;
        return false;
    }

    return true;
}

bool JsonFileParser::parseMainObject(QJsonObject &jsonObj)
{
    bool parseOk = true;

    // Extracting the main JsonArray which holds all data
    QJsonArray dataList = jsonObj[DATA_LIST].toArray();

    if(dataList.isEmpty())
    {
        qDebug() <<  "JsonFileParser::parseMainObject - Object not found.";
        return false;
    }

    // Iterating over each object inside Data List
    // Each element refers to a single TestCase
    for(QJsonValue seriesVal : dataList)
    {
        QJsonObject tmpTestData = seriesVal.toObject();
        parseOk &= !tmpTestData.isEmpty();
        QJsonObject tmpInputDataObj = tmpTestData[INPUT_DATA].toObject();
        parseOk &= !tmpInputDataObj.isEmpty();
        QJsonObject tmpVerificationDataObj = tmpTestData[VERIFICATION_DATA].toObject();
        parseOk &= !tmpVerificationDataObj.isEmpty();

        // Populating TestCaseInfo with the extracted information
        TestCaseInfo testInfo;

        testInfo.setTestCaseID(tmpTestData[TEST_CASE_ID].toString());
        testInfo.insertInputDataElement(BASE, tmpInputDataObj[BASE].toString());
        testInfo.insertInputDataElement(EXP, tmpInputDataObj[EXP].toString());

        testInfo.insertVerificationDataElement(EXPECTED_RESULT, tmpVerificationDataObj[EXPECTED_RESULT].toString());

        // Once all data have been extracted, TestCaseInfo is now appended
        // to the TestCaseInfo List
        testCaseInfoList.append(testInfo);
    }

    return parseOk;
}

QList<TestCaseInfo> JsonFileParser::getTestCaseInfoList() const
{
    return testCaseInfoList;
}

QString JsonFileParser::getFileName() const
{
    return fileName;
}

void JsonFileParser::setFileName(const QString &value)
{
    fileName = value;
}
