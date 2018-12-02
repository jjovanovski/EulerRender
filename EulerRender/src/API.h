#pragma once

#ifdef EULER_EXPORTS
#define EULER_API __declspec(dllexport)
#else
#define EULER_API __declspec(dllimport)
#endif