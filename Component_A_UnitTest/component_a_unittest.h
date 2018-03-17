/**
 *
 * @file component_a_unittest.h
 * @author Andrea Toscano
 * @version 1.0
 *
 * @brief Main class that implements the data driven
 * Unit Test for the Component_A Class
 * @section DESCRIPTION
 *
 * Component_A_UnitTest is responsible for gathering the
 * input and verification data and launching the execution of the tests
 *
 * The Class implementing the test must inherit from QObject
 * in order to be executed by QTest::qExec()
 *
**/

#ifndef COMPONENT_A_UNITTEST_H
#define COMPONENT_A_UNITTEST_H

#include <QtTest/QtTest>
#include <QObject>
#include <QString>
#include <QDebug>
#include <QSharedDataPointer>

#include "component_a.h"
#include "jsonfileparser.h"
#include "testcaseinfo.h"
#include "component_a_unittest_definitions.h"

using namespace UnitTestNamespace;

// Forward declaration of SharedData where all classed
// needed for this test are stored
class Component_A_UnitTest_Data;


class Component_A_UnitTest : public QObject
{
    Q_OBJECT
public:
    Component_A_UnitTest();
    ~Component_A_UnitTest();

    /**
     * @brief parseConfigurationFile Calls JsonFileParser responsible
     * for parsing and storing all data needed for the tests
     * @param configFileName Name of the json configuration file
     * @return TRUE in case of positive parsing, FALSE, otherwise.
     */
    bool parseConfigurationFile(QString configFileName);

private slots:
    /**
     * @brief initTestCase Called only once at the beginning of the test execution.
     * Used mainly for instantiating the objects used during the entire test execution.
     */
    void initTestCase();

    /**
     * @brief cleanupTestCase Called once all tests have been run.
     */
    void cleanupTestCase();

    /**
     * @brief init Called before the execution of each Test. It's intended to be
     * used to clean or reset objects and variables between each Test Execution.
     */
    void init();

    /**
     * @brief cleanup Called after the execution of each Test.
     * Uset to cleanup used variables and objects.
     */
    void cleanup();

    /**
     * @brief testProcedurePow Responsible for launching a single Test procedure
     * and usually run the verification steps.
     */
    void testProcedurePow();

    /**
     * @brief testProcedurePow_data Used to create and fill the table that defines
     * all the tests that will run automatically.
     *
     * Columns names represent the parameters we want to fetch during each Test Procedure
     * execution.
     * Each row represents an instance of Test Case i.e. Test Procedure.
     * Example:
     * TEST_CASE_ID    BASE    EXP    EXPECTED RESULT
     * test-case-01    2       3      8
     * test-case-02    3       3      27
     *
     * QTest will go through the table row by row and call testProcedurePow() providing it
     * the values belonging to the current row.
    **/
    void testProcedurePow_data();

private:
    QSharedDataPointer<Component_A_UnitTest_Data> testData;
};

#endif // COMPONENT_A_UNITTEST_H
