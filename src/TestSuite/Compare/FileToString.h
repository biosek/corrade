#ifndef Corrade_TestSuite_Compare_FileToString_h
#define Corrade_TestSuite_Compare_FileToString_h
/*
    This file is part of Corrade.

    Copyright © 2007, 2008, 2009, 2010, 2011, 2012, 2013
              Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

/** @file
 * @brief Class Corrade::TestSuite::Compare::FileToString
 */

#include "TestSuite/Comparator.h"

#include "TestSuite/corradeTestSuiteVisibility.h"

namespace Corrade { namespace TestSuite {

namespace Compare {

/**
@brief Pseudo-type for comparing file contents to string

Prints the length of both files (if they are different) and prints value
and position of first different character in both files. Example usage:
@code
CORRADE_COMPARE_AS("actual.txt", "expected file contents", Compare::FileToString);
@endcode

See @ref Comparator-pseudo-types for more information.
*/
class FileToString {};

}

#ifndef DOXYGEN_GENERATING_OUTPUT
template<> class CORRADE_TESTSUITE_EXPORT Comparator<Compare::FileToString> {
    public:
        Comparator();

        bool operator()(const std::string& filename, const std::string& expectedContents);

        void printErrorMessage(Utility::Error& e, const std::string& actual, const std::string& expected) const;

    private:
        enum class State {
            Success,
            ReadError
        };

        State state;
        std::string filename,
            actualContents, expectedContents;
};
#endif

}}

#endif
