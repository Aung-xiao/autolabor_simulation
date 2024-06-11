#ifndef ROS_CODE__VISIBILITY_CONTROL_H_
#define ROS_CODE__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROS_CODE_EXPORT __attribute__ ((dllexport))
    #define ROS_CODE_IMPORT __attribute__ ((dllimport))
  #else
    #define ROS_CODE_EXPORT __declspec(dllexport)
    #define ROS_CODE_IMPORT __declspec(dllimport)
  #endif
  #ifdef ROS_CODE_BUILDING_LIBRARY
    #define ROS_CODE_PUBLIC ROS_CODE_EXPORT
  #else
    #define ROS_CODE_PUBLIC ROS_CODE_IMPORT
  #endif
  #define ROS_CODE_PUBLIC_TYPE ROS_CODE_PUBLIC
  #define ROS_CODE_LOCAL
#else
  #define ROS_CODE_EXPORT __attribute__ ((visibility("default")))
  #define ROS_CODE_IMPORT
  #if __GNUC__ >= 4
    #define ROS_CODE_PUBLIC __attribute__ ((visibility("default")))
    #define ROS_CODE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ROS_CODE_PUBLIC
    #define ROS_CODE_LOCAL
  #endif
  #define ROS_CODE_PUBLIC_TYPE
#endif
#endif  // ROS_CODE__VISIBILITY_CONTROL_H_
// Generated 10-Jun-2024 16:04:41
// Copyright 2019-2020 The MathWorks, Inc.
