
#ifndef DETAIL_GZ_MATH_VISIBLE_H
#define DETAIL_GZ_MATH_VISIBLE_H

#ifdef GZ_MATH_STATIC_DEFINE
#  define DETAIL_GZ_MATH_VISIBLE
#  define DETAIL_GZ_MATH_HIDDEN
#else
#  ifndef DETAIL_GZ_MATH_VISIBLE
#    ifdef gz_math_EXPORTS
        /* We are building this library */
#      define DETAIL_GZ_MATH_VISIBLE __declspec(dllexport)
#    else
        /* We are using this library */
#      define DETAIL_GZ_MATH_VISIBLE __declspec(dllimport)
#    endif
#  endif

#  ifndef DETAIL_GZ_MATH_HIDDEN
#    define DETAIL_GZ_MATH_HIDDEN 
#  endif
#endif

#ifndef GZ_DEPRECATED_ALL_VERSIONS
#  define GZ_DEPRECATED_ALL_VERSIONS __declspec(deprecated)
#endif

#ifndef GZ_DEPRECATED_ALL_VERSIONS_EXPORT
#  define GZ_DEPRECATED_ALL_VERSIONS_EXPORT DETAIL_GZ_MATH_VISIBLE GZ_DEPRECATED_ALL_VERSIONS
#endif

#ifndef GZ_DEPRECATED_ALL_VERSIONS_NO_EXPORT
#  define GZ_DEPRECATED_ALL_VERSIONS_NO_EXPORT DETAIL_GZ_MATH_HIDDEN GZ_DEPRECATED_ALL_VERSIONS
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef GZ_MATH_NO_DEPRECATED
#    define GZ_MATH_NO_DEPRECATED
#  endif
#endif

#endif /* DETAIL_GZ_MATH_VISIBLE_H */
