/**
 * Direct access DB
 * База данных прямого доступа
 * Эмуляция файла с прямым доступом
 */

#ifndef DDB_H
#define DDB_H

#include <cstdio>

#include "record.h"

class DDB
{
	char *filename;
	FILE *f;
	bool createFile();
public:
	DDB(char *filename);

	void Find(int key, Record &s);
	void Write(const Record &s);
	void Delete(const Record &s);
	void Sort();
};

#endif // DDB_H
