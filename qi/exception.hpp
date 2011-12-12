/**
 * @author Victor Paleologue
 * Copyright (c) Aldebaran Robotics 2011 All Rights Reserved
 */

#pragma once

#ifndef _LIBQI_QI_EXCEPTION_HPP_
#define _LIBQI_QI_EXCEPTION_HPP_

#include <stdexcept>

namespace qi
{
  /// @brief Thrown generic exception for i/o errors.
  class ioerror : public std::runtime_error
  {
  public:
    ioerror(const std::string& what) : std::runtime_error(what) { }
  };

  /// @brief Thrown on read errors.
  class ioreaderror : public ioerror
  {
  public:
    ioreaderror(const std::string& what) : ioerror(what) { }
  };

  /// @brief Thrown on write errors.
  class iowriteerror : public ioerror
  {
  public:
    iowriteerror(const std::string& what) : ioerror(what) { }
  };

  /// @brief Thrown on critical data format mismatch.
  class corruptionerror : public std::runtime_error
  {
  public:
    corruptionerror(const std::string& what) : std::runtime_error(what) { }
  };
}

#endif // _LIBQI_QI_EXCEPTION_HPP_