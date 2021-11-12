

#ifndef BSPLINE_VISBILITY_H
#define BSPLINE_VISBILITY_H

#if defined(_MSC_VER) && defined(BSPLINE_SHARED)
    #ifdef BSPLINE_BUILD
        #define BSPLINE_PUBLIC __declspec(dllexport)
    #else
        #define BSPLINE_PUBLIC __declspec(dllimport)
    #endif
#else
    #define BSPLINE_PUBLIC
#endif

#endif