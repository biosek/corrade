#ifndef Corrade_PluginManager_Test_AbstractDeletable_h
#define Corrade_PluginManager_Test_AbstractDeletable_h
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

#include "PluginManager/AbstractPlugin.h"

namespace Corrade { namespace PluginManager { namespace Test {

class AbstractDeletable: public AbstractPlugin {
    CORRADE_PLUGIN_INTERFACE("cz.mosra.Corrade.PluginManager.Test.AbstractDeletable/1.0")

    protected:
        unsigned int* var;

    public:
        explicit AbstractDeletable(AbstractManager* manager, std::string plugin): AbstractPlugin(manager, std::move(plugin)) {}

        void set(unsigned int* var) { this->var = var; }

        bool canBeDeleted() { return true; }
};

}}}

#endif
