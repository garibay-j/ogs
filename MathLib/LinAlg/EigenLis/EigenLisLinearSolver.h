/**
 * \copyright
 * Copyright (c) 2012-2015, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#ifndef EIGENLISLINEARSOLVER_H_
#define EIGENLISLINEARSOLVER_H_

#include <vector>

#include <boost/property_tree/ptree_fwd.hpp>
#include <lis.h>

#include "MathLib/LinAlg/Lis/LisOption.h"

namespace MathLib
{
class EigenVector;
class EigenMatrix;

/**
 * Linear solver using Lis library with Eigen matrix and vector objects
 */
class EigenLisLinearSolver
{
public:
    /**
     * Constructor
     * @param A         Coefficient matrix object
     * @param option    A pointer to a linear solver option. In case you omit
     *                  this argument, default settings follow those of
     *                  LisOption struct.
     */
    EigenLisLinearSolver(EigenMatrix &A, boost::property_tree::ptree const*const option = nullptr);

    virtual ~EigenLisLinearSolver() {}

    /**
     * configure linear solvers
     * @param option
     */
    void setOption(const boost::property_tree::ptree &option);

    /**
     * configure linear solvers
     * @param option
     */
    void setOption(const LisOption &option) { _option = option; }

    /**
     * get linear solver options
     * @return
     */
    LisOption &getOption() { return _option; }

    /**
     * solve a given linear equations
     *
     * @param b     RHS vector
     * @param x     Solution vector
     */
    void solve(EigenVector &b, EigenVector &x);

private:
    EigenMatrix& _A;
    LisOption _option;
};

} // MathLib

#endif //EIGENLISLINEARSOLVER_H_

