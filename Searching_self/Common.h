#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#pragma once
#include <string>
#include <vector>
#include <io.h>
#include <iostream>
#include <set>

#include <thread>
#include<mutex>
#include<condition_variable>

#include<algorithm>
#include<windows.h>

#include "./sqlite/sqlite3.h"
#pragma comment(lib, "./sqlite/sqlite3.lib")
#include "Config.h"

#define MAX_TITLE_SIZE  128
