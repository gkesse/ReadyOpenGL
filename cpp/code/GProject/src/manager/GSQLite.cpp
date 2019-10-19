//================================================
#include "GSQLite.h"
#include "GString.h"
//================================================
GSQLite* GSQLite::m_instance = 0;
//================================================
GSQLite::GSQLite() {

}
//================================================
GSQLite::~GSQLite() {
	
}
//================================================
GSQLite* GSQLite::Instance() {
	if(m_instance == 0) {
		m_instance = new GSQLite;
	}
	return m_instance;
}
//================================================
void GSQLite::open(const string& sqliteName, const string& dbPath) {
	sqlite3* lSqlite;
	int lOk = sqlite3_open(dbPath.c_str(), &lSqlite);
	if(lOk != SQLITE_OK) {cout << "[ GSQLite ] Error GSQLite::open\n"; exit(1);}
	m_sqliteMap[sqliteName] = lSqlite;
}
//================================================
void GSQLite::exec(const string& sqliteName, GSQLITE_CALLBACK_EXEC callback, void* params, const string& sqlQuery) {
	sqlite3* lSqlite = m_sqliteMap[sqliteName];
	char* lError;
	int lOk = sqlite3_exec(lSqlite, sqlQuery.c_str(), callback, params, &lError);
	if(lOk != SQLITE_OK) {cout << "[ GSQLite ] Error GSQLite::exec : " << lError << "\n"; exit(1);}
	sqlite3_free(lError);
}
//================================================
int GSQLite::lastId(const string& sqliteName) {
	sqlite3* lSqlite = m_sqliteMap[sqliteName];
	int lLastId = sqlite3_last_insert_rowid(lSqlite);
	return lLastId;
}
//================================================
void GSQLite::prepareV2(const string& sqliteName, const string& stmtName, const string& sqlQuery) {
	sqlite3* lSqlite = m_sqliteMap[sqliteName];
	sqlite3_stmt* lStmt;
	int lOk = sqlite3_prepare_v2(lSqlite, sqlQuery.c_str(), -1, &lStmt, 0);
	if(lOk != SQLITE_OK) {cout << "[ GSQLite ] Error GSQLite::prepareV2 : " << sqlite3_errmsg(lSqlite) << "\n"; exit(1);}
	m_stmtMap[stmtName] = lStmt;
}
//================================================
void GSQLite::bindInt(const string& sqliteName, const string& stmtName, const int& index, const int& value) {
	sqlite3* lSqlite = m_sqliteMap[sqliteName];
	sqlite3_stmt* lStmt = m_stmtMap[stmtName];
	int lOk = sqlite3_bind_int(lStmt, index, value);
	if(lOk != SQLITE_OK) {cout << "[ GSQLite ] Error GSQLite::bindInt : " << sqlite3_errmsg(lSqlite) << "\n"; exit(1);}
}
//================================================
void GSQLite::bindParameterIndexInt(const string& sqliteName, const string& stmtName, const string& parameterIndex, const int& value) {
	sqlite3* lSqlite = m_sqliteMap[sqliteName];
	sqlite3_stmt* lStmt = m_stmtMap[stmtName];
	int lIndex = sqlite3_bind_parameter_index(lStmt, parameterIndex.c_str());
	int lOk = sqlite3_bind_int(lStmt, lIndex, value);
	if(lOk != SQLITE_OK) {cout << "[ GSQLite ] Error GSQLite::bindParameterIndexInt : " << sqlite3_errmsg(lSqlite) << "\n"; exit(1);}
}
//================================================
void GSQLite::bindBold(const string& sqliteName, const string& stmtName, const int& index, void* data, const int& size) {
	sqlite3* lSqlite = m_sqliteMap[sqliteName];
	sqlite3_stmt* lStmt = m_stmtMap[stmtName];
	int lOk = sqlite3_bind_blob(lStmt, index, data, size, SQLITE_STATIC);
	if(lOk != SQLITE_OK) {cout << "[ GSQLite ] Error GSQLite::bindBold : " << sqlite3_errmsg(lSqlite) << "\n"; exit(1);}
}
//================================================
int GSQLite::step(const string& stmtName) {
	sqlite3_stmt* lStmt = m_stmtMap[stmtName];
	int lOk = sqlite3_step(lStmt);
	return lOk;
}
//================================================
const uchar* GSQLite::columnText(const string& stmtName, const int& index) {
	sqlite3_stmt* lStmt = m_stmtMap[stmtName];
	const uchar* lText = sqlite3_column_text(lStmt, index);
	return lText;
}
//================================================
int GSQLite::columnBytes(const string& stmtName, const int& index) {
	sqlite3_stmt* lStmt = m_stmtMap[stmtName];
	int lBytes = sqlite3_column_bytes(lStmt, index);
	return lBytes;
}
//================================================
const void* GSQLite::columnBlob(const string& stmtName, const int& index) {
	sqlite3_stmt* lStmt = m_stmtMap[stmtName];
	const void* lData = sqlite3_column_blob(lStmt, index);
	return lData;
}
//================================================
int GSQLite::getAutocommit(const string& sqliteName) {
	sqlite3* lSqlite = m_sqliteMap[sqliteName];
	int lAutocommit = sqlite3_get_autocommit(lSqlite);
	return lAutocommit;
}
//================================================
void GSQLite::finalize(const string& stmtName) {
	sqlite3_stmt* lStmt = m_stmtMap[stmtName];
	sqlite3_finalize(lStmt);
}
//================================================
void GSQLite::close(const string& sqliteName) {
	sqlite3* lSqlite = m_sqliteMap[sqliteName];
	int lOk = sqlite3_close(lSqlite);
	if(lOk != SQLITE_OK) {cout << "[ GSQLite ] Error GSQLite::close : " << "\n"; exit(1);}
}
//================================================
void GSQLite::showTableList(const string& sqliteName) {
	cout << "[ TABLES ]:\n";
	this->exec(sqliteName, showTableListCallback, 0,
			"SELECT name FROM sqlite_master "
			"WHERE type = 'table' "
			"ORDER BY 1");
	cout << "\n";
}
//================================================
void GSQLite::showTableData(const string& sqliteName, const string& tableName) {
	string lTableName = GString::Instance()->toUpper(tableName);
	string lSqlQuery = "SELECT * FROM " + lTableName;
	this->exec(sqliteName, showTableDataCallback, (char*)lTableName.c_str(), lSqlQuery);
}
//================================================
int GSQLite::showTableListCallback(void* params, int colCount, char** colValues, char** colNames) {
	for(int i = 0; i < colCount; i++) {
		const char* lColValue = (colValues[i]) ? colValues[i] : "NULL";
		cout << "- " << lColValue << "\n";
	}
	return 0;
}
//================================================
int GSQLite::showTableDataCallback(void* params, int colCount, char** colValues, char** colNames) {
	char* lTableName = (char*)params;
	cout << "[ " << lTableName << " ]:\n";
	for(int i = 0; i < colCount; i++) {
		const char* lColName = GString::Instance()->toUpper(colNames[i]).c_str();
		const char* lColValue = (colValues[i]) ? colValues[i] : "NULL";
		cout << left << setw(15) << lColName << " : " << lColValue << "\n";
	}
	cout << "\n";
	return 0;
}
//================================================
