#include "Common.h"

void DirectionList(const string &path, vector<string>& filename, vector<string>& subdir);

//日志模块
#ifndef __TRACE__
 //#define __TRACE__
#endif

#ifndef __DEBUG__
	//#define __DEBUG__
#endif

// 用于调试追溯的trace log
inline static void __TraceDebug(const char* filename, int line,
	const char* function, const char* format, ...)
{
#ifdef __TRACE__
	//输出调用函数的信息
	fprintf(stdout, "[TRACE][%s:%d : %s]:", GetFileName(filename).c_str(), line, function);
	//输出用户打的trace信息
	va_list args;
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);
	fprintf(stdout, "\n");
#endif
}

inline static void __ErrorDebug(const char* filename, int line,
	const char* function, const char* format, ...)
{
#ifdef __DEBUG__
	//输出调用函数的信息
	fprintf(stdout, "[ERROR][%s:%d:%s]:", GetFileName(filename).c_str(), line, function);
	//输出用户打的trace信息
	va_list args;
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);
	fprintf(stdout, " errmsg:%s, errno:%d\n", strerror(errno),
		errno);
#endif
}

#define TRACE_LOG(...) __TraceDebug(__FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);
#define ERROR_LOG(...) __ErrorDebug(__FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);


size_t GetFileCount(const string &path);

// 汉字转拼音全拼
string ChineseConvertPinYinAllSpell(const string& dest_chinese);
// 汉字转拼音首字母
string ChineseConvertPinYinInitials(const std::string& name);


void ColourPrintf(const char* str);

size_t GetFileCount(const string &path);