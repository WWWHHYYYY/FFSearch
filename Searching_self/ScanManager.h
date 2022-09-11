#pragma once
#include"DataManager.h"


//增加同步扫描模块
//单例模式
class ScanManager
{
public:
	static ScanManager& CreateScanManagerObj(const string &path);
public:
	void StartScan(const string &path);
	void ScanDirection(const string &path);
	void StartWatch(const string &path);
	bool DirectionWatch(const string &path);
private:
	ScanManager();
private:
	//DataManager m_dm;
	static ScanManager _sm_inst;
	mutex m_mutex;
	condition_variable m_cond;
};

