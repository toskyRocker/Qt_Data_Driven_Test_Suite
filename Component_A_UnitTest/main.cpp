/**
 *
 * @file main.cpp
 * @author Andrea Toscano
 * @version 1.0
 *
 * @brief Main that launches the execution of the Component_A
 * Unit Test.
 * @section DESCRIPTION
 *
 * The main instantiates a Component_A_UnitTest object,
 * it reads the configuration file name passed by command line
 * and launches the execution of the test.
 *
 * At the end of the execution, the Test results are saved on a
 * xml file.
**/

#include <QCoreApplication>
#include <QDebug>
#include <QtTest/QtTest>
#include <QFileInfo>
#include <memory>

#include "component_a_unittest.h"

void printUsage()
{
    qInfo() << "*********************************************************************************";
    qInfo() << "Usage: -config [configuration_file_name]";
    qInfo() << "-config : tag that expects a following configuration file name with .json ext.";
    qInfo() << "Example : -config unit_test_data_1.json";
    qInfo() << "*********************************************************************************";
    qInfo() << "";
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
//    QLoggingCategory::setFilterRules("*.debug=false");

    /** Override this variable if you need more than 5 Mins
    * To execute a single TestCase
    * The value has to be in MilliSeconds **/
    qputenv("QTEST_FUNCTION_TIMEOUT", "600000"); // 10 Min


    // Instantiating the object responsible for running the tests
    std::unique_ptr<Component_A_UnitTest> testRunner(new Component_A_UnitTest);

    // Parsing the command line arguments
    int idxOfCurrentArg = -1;
    bool initOk = true;
    QStringList programArgs = qApp->arguments();
    QString config = "";

    if ((idxOfCurrentArg = programArgs.indexOf(QRegExp("-config", Qt::CaseInsensitive))) != -1)
    {
        if (idxOfCurrentArg == programArgs.size()-1)
        {
            qDebug() << "Main: No Input provided. Check Usage.";
            printUsage();
            return -1;
        }
        else
        {
            // Removing everything that's before -config
            for(int index = 0; index <= idxOfCurrentArg; index++)
                programArgs.removeAt(0);


            if(programArgs.size() != 1)
            {
                qDebug() << "Main: Too many input args. See usage";
                printUsage();
                return -1;
            }

            for(QString configFile : programArgs)
            {
                if(configFile.startsWith("-"))
                    break;

                qDebug() << "Main: Config File found: " << configFile;
                config=configFile;
                initOk &= testRunner->parseConfigurationFile(configFile);
                if(!initOk)
                    return -1;
            }
        }
    }

    // Calling the execution of the tests
    int status = 0;
    QFileInfo file(config);
    QString fileName =  file.baseName()+"_result.xml";
    QStringList testCmd = QStringList() << " " <<  "-xml" << "-o" << fileName;
    status = QTest::qExec(testRunner.get(), testCmd);

    return status;
}
