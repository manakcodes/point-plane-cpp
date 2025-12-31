#pragma once
#include <iostream>
#include <float.h>
#include <math.h>

#include <limits>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

namespace COMPARE_DOUBLE
{
    // ====================================================================== //
    // EPSILON to check values against it (MAX TOLERANCE)
    // ====================================================================== //
    const double EPSILON = 1E-4;

    // ====================================================================== //
    // @brief checks if x is NAN or not
    // ====================================================================== //
    inline bool IS_NAN(double x)
    {
        return std::isnan(x);
    }

    // ====================================================================== //
    // @brief checks if a `double` is effectively `ZERO`
    // ====================================================================== //
    inline bool IS_ZERO(double x)
    {
        return std::fabs(x) < EPSILON;
    }

    // ====================================================================== //
    // @brief checks if a `double` is effectively `ONE`
    // ====================================================================== //
    inline bool IS_ONE(double x)
    {
        return std::fabs(x - 1.0000) < EPSILON;
    }

    // ====================================================================== //
    // @brief checks if a `double` is positive beyond `EPSILON`
    // ====================================================================== //
    inline bool IS_POSITIVE(double x)
    {
        return x > EPSILON;
    }

    // ====================================================================== //
    // @brief checks if a `double` is negative beyond `EPSILON`
    // ====================================================================== //
    inline bool IS_NEGATIVE(double x)
    {
        return x < -EPSILON;
    }

    // ====================================================================== //
    // @brief checks if two `doubles` are effectively `EQUAL`
    // ====================================================================== //
    inline bool IS_EQUAL(double a, double b)
    {
        return std::fabs(a - b) < EPSILON;
    }

    // ====================================================================== //
    // @brief checks if a is greater than b considering `EPSILON`
    // ====================================================================== //
    inline bool IS_GREATER(double a, double b)
    {
        return (a - b) >= EPSILON;
    }

    // ====================================================================== //
    // @brief checks if a is less than b considering `EPSILON`
    // ====================================================================== //
    inline bool IS_LESS(double a, double b)
    {
        return (b - a) > EPSILON;
    }

    // ====================================================================== //
    // @brief checks if a is greater than or equal to b
    // ====================================================================== //
    inline bool IS_GREATER_THAN_EQUAL_TO(double a, double b)
    {
        return (a > b) || IS_EQUAL(a, b);
    }

    // ====================================================================== //
    // @brief checks if a is less than or equal to b
    // ====================================================================== //
    inline bool IS_LESS_THAN_EQUAL_TO(double a, double b)
    {
        return (a < b) || IS_EQUAL(a, b);
    }

}

// ========================================================================== //
// namespace for terminal styles output
// ========================================================================== //
namespace TERMINAL_STYLES
{
    /**
     * =========================================================================
     * @brief set `terminal` text color to `RED`
     * =========================================================================
     */
    const char *RED = "\033[31m";

    /**
     * =========================================================================
     * @brief set `terminal` text color to `BLUE`
     * =========================================================================
     */
    const char *BLUE = "\033[34m";

    /**
     * =========================================================================
     * @brief set `terminal` text color to `GREEN`
     * =========================================================================
     */
    const char *GREEN = "\033[32m";

    /**
     * =========================================================================
     * @brief set `terminal` text color to cyan
     * =========================================================================
     */
    const char *CYAN = "\033[36m";

    /**
     * =========================================================================
     * @brief set `terminal` text color to magenta
     * =========================================================================
     */
    const char *MAGENTA = "\033[35m";

    /**
     * =========================================================================
     * @brief set `terminal` text formatting to bold
     * =========================================================================
     */
    const char *BOLD = "\033[1m";

    /**
     * =========================================================================
     * @brief set `terminal` text formatting to underline
     * =========================================================================
     */
    const char *UNDERLINE = "\033[4m";

    /**
     * =========================================================================
     * @brief reset `terminal` text formatting
     * =========================================================================
     */
    const char *RESET = "\033[0m";
}
