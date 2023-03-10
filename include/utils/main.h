#ifndef MAIN_H
#define MAIN_H

#include <memory>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdlib>
#include <cstring>
#include <string>
#include <filesystem>
#include <future>

#include "xpack/json.h" // Json包含这个头文件，xml则包含xpack/xml.

#include <yaml-cpp/yaml.h>

#include"loguru.hpp"
#include "co/all.h"
#include "mytime.hpp"

struct YamlParam
{
  string userName;
  string passWord;
  string serialNum;

  string pcLocalIP;
  string pcRemoteIP;
  string cppLocalIP;
  string cppRemoteIP;
  string javaLocalIP;
  string javaRemoteIP;
  string PLCIP;
  string PLCPort;
  string sendPLCPort;
  string rcvPLCPort;

  bool debugPC2;
  bool debugCpp;
  bool debugJava;
};


#endif // MAIN_H
