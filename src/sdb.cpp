#include "sdb.h"
#include "record.h"
#include "files.h"

void SDB::FindWithCopy() {}

SDB::SDB(char *filename) : filename(filename) {}

void SDB::Find(int key, Record &s) {
	if((f = fopen(filename, "rb")) == NULL) {
		return;
	}

	read(s, f);
	while(!feof(f) && s.id != key) {
		read(s, f);
	}

	if (s.id != key) {
		s.id = -1;
	}
	fclose(f);
}

// also call FindWithCopy inside
void SDB::Append(const Record &s) {}
void SDB::Insert(const Record &s) {}
void SDB::Update(const Record &s) {}
void SDB::Delete(const Record &s) {}
void SDB::Sort() {}
