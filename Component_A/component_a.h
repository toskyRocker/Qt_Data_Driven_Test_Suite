/**
 *
 * @file component_a.h
 * @author Andrea Toscano
 * @version 1.0
 *
 * @brief Simple Class that contains only one function
 * @section DESCRIPTION
 *
 * This oversimplified class has to be intented as
 * component under test
 *
 *
**/

#ifndef COMPONENT_A_H
#define COMPONENT_A_H

#include "component_a_global.h"


class COMPONENT_ASHARED_EXPORT Component_A
{

public:
    Component_A();
    virtual ~Component_A();

    /**
     * @brief doPow Takes to float numbers and performs
     * the exponentiation
     * @param base Float number used for the base
     * @param exp Float number used for the exponent
     * @return base^exp
     */
    int doPow(int base, int exp);
};


#endif // COMPONENT_A_H
