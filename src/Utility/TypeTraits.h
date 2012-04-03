#ifndef Corrade_Utility_TypeTraits_h
#define Corrade_Utility_TypeTraits_h
/*
    Copyright © 2007, 2008, 2009, 2010, 2011, 2012
              Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Corrade.

    Corrade is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Corrade is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

/** @file
 * @brief Type traits
 */

#include <type_traits>

namespace Corrade { namespace Utility {

/**
@brief Cast value of strongly typed enum to its underlying type
@param enumValue    Enum value

Shorthand for verbose code such as this:
@code
enum class Enum: unsigned int {
    Value
};

unsigned int value = static_cast<std::underlying_type<Enum>::type>(Enum::Value);
unsigned int value = castToUnderlyingType(Enum::Value);
@endcode
*/
template<class T> constexpr auto castToUnderlyingType(T enumValue) -> typename std::underlying_type<T>::type {
    return static_cast<typename std::underlying_type<T>::type>(enumValue);
}

/**
@brief Macro for creating traits class for checking whether an class has given inner type
@param type         Inner type to look for
@param className    Resulting trait class name

See @ref Corrade::Utility::IsIterable "IsIterable" class documentation for an example.
*/
/* Two overloaded get() functions return type of different size. Templated
   get() is used when T has given attribute, non-templated otherwise. Bool
   value then indicates whether the templated version was called or not. */
#define HasType(type, className)                                            \
template<class T> class className {                                         \
    typedef char SmallType;                                                 \
    typedef short LargeType;                                                \
                                                                            \
    template<class U> static SmallType get(U&, typename U::type* = nullptr);\
    static LargeType get(...);                                              \
    static T& reference();                                                  \
                                                                            \
    public:                                                                 \
        static const bool value =                                           \
            sizeof(get(reference())) == sizeof(SmallType);                  \
};

#ifdef DOXYGEN_GENERATING_OUTPUT
/**
@brief Traits class for checking whether given class is iterable (via const_iterator)

Actually created using HasType macro:
@code
HasType(const_iterator, IsIterable)
@endcode
*/
template<class T> class IsIterable {
    /**
     * @brief Whether given class is iterable
     *
     * True when given class has const_iterator, false otherwise.
     */
    static const bool value;
}
#else
HasType(const_iterator, IsIterable)
#endif

}}

#endif
