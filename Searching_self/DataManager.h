#pragma once
#include"Common.h"




class SqliteManager
{
public:
	SqliteManager();
	~SqliteManager();
public:
	void Open(const string &path);		//打开数据库
	void Close();						//关闭数据库
	void ExcuteSql(const string &sql);	//执行
	void GetResultTable(const string &sql, char **&ppRet, int &row, int &col);
private:
	sqlite3* m_db;
};

//自动获取，释放结果表 RAII
class AutoGetResultTable
{
public:
	AutoGetResultTable(SqliteManager *db, const string& sql, char **&ppRet, int &row, int &col);
	~AutoGetResultTable();
public:
	AutoGetResultTable(const AutoGetResultTable &) = delete;
	AutoGetResultTable& operator=(const AutoGetResultTable &) = delete;
private:
	SqliteManager* m_db;
	char **m_ppRet;
};

//封装数据管理类
class DataManager
{
public:
	static DataManager& GetDataManagerObj();
private:
	DataManager();
	~DataManager();
public:
	void Search(const string &key, vector<pair<string, string>> &doc_path);
	static void SplitHighlight(const string &str, const string &key,
		string &prefix, string &highlight, string &suffix);
public:
	void InitSqlite();
	void InsertDoc(const string &path, const string &doc);
	void DeleteDoc(const string &path, const string &doc);
	void GetDocs(const string &path, multiset<string> &docs);
private:
	SqliteManager m_dbmgr;
	static DataManager _dm_inst;
};
// 静态成员，类外初始化
