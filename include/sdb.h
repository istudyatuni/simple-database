/**
 * Sequential access DB
 * База данных последовательного доступа
 * Эмуляция файла с последовательным доступом
 */

#ifndef SDB_H
#define SDB_H

#include <cstdio>

#include "record.h"

class SDB
{
	char *filename, filename_copy[100] = "copy-";
	FILE *f, *fcopy;
	void FindWithCopy(int key);
	void FinishCopy();
public:
	SDB(char *filename);

	void Find(int key, Record &s);
	void Append(const Record &s);
	void Insert(const Record &s);
	void Update(const Record &s);
	void Delete(const Record &s);
	void Sort();
};

#endif // SDB_H
