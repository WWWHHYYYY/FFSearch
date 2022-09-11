#pragma once
#include"Common.h"




class SqliteManager
{
public:
	SqliteManager();
	~SqliteManager();
public:
	void Open(const string &path);		//�����ݿ�
	void Close();						//�ر����ݿ�
	void ExcuteSql(const string &sql);	//ִ��
	void GetResultTable(const string &sql, char **&ppRet, int &row, int &col);
private:
	sqlite3* m_db;
};

//�Զ���ȡ���ͷŽ���� RAII
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

//��װ���ݹ�����
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
// ��̬��Ա�������ʼ��
