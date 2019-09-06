//================================================
#ifndef _GSQLite_
#define _GSQLite_
//================================================
#include "GInclude.h"
//================================================
typedef int (*GSQLITE_CALLBACK_EXEC)(void* params, int colCount, char** colValues, char** colNames);
//================================================
class GSQLite {
private:
	GSQLite();
	
public:
	~GSQLite();
	static GSQLite* Instance();
	void open(const string& sqliteName, const string& dbPath);
	void exec(const string& sqliteName, GSQLITE_CALLBACK_EXEC callback, void* params, const string& sqlQuery);
	int lastId(const string& sqliteName);
	void prepareV2(const string& sqliteName, const string& stmtName, const string& sqlQuery);
	void bindInt(const string& sqliteName, const string& stmtName, const int& index, const int& value);
	void bindParameterIndexInt(const string& sqliteName, const string& stmtName, const string& parameterIndex, const int& value);
	void bindBold(const string& sqliteName, const string& stmtName, const int& index, void* data, const int& size);
	int step(const string& stmtName);
	const uchar* columnText(const string& stmtName, const int& index);
	int columnBytes(const string& stmtName, const int& index);
	const void* columnBlob(const string& stmtName, const int& index);
	int getAutocommit(const string& sqliteName);
	void finalize(const string& stmtName);
	void close(const string& sqliteName);
	void showTableList(const string& sqliteName);
	void showTableData(const string& sqliteName, const string& tableName);
	static int showTableListCallback(void* params, int colCount, char** colValues, char** colNames);
	static int showTableDataCallback(void* params, int colCount, char** colValues, char** colNames);

private:
	static GSQLite* m_instance;
	map<string, sqlite3*> m_sqliteMap;
	map<string, sqlite3_stmt*> m_stmtMap;
};
//================================================
#endif
//================================================
