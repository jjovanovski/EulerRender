#pragma once

#ifdef __GNUC__

#ifdef EULER_EXPORTS
#define EULER_API __attribute__((visibility("default")))
#else
#define EULER_API
#endif

#else

#ifdef EULER_EXPORTS
#define EULER_API __declspec(dllexport)
#else
#define EULER_API __declspec(dllimport)
#endif

#endif
