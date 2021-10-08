#include <cstdio>

#include "ddb.h"
#include "files.h"

DDB::DDB(char *filename) : filename(filename) {}

bool DDB::createFile() {
	if((this->f = fopen(this->filename, "w")) == NULL) {
		return false;
	}
	return true;
}

void DDB::Find(int key, Record &s) {
	if((this->f = fopen(this->filename, "rb")) == NULL) {
		return;
	}

	seek_from_begin_file(key, this->f);
	read_from_file(s, this->f);
	fclose(this->f);
}

/**
 * Insert/update record
 * @param s Record
 */
void DDB::Write(const Record &s) {
	// r+ for not overwrite other entries
	if((this->f = fopen(this->filename, "rb+")) == NULL) {
		if (!this->createFile()) {
			return;
		}
	}

	seek_from_begin_file(s.id, this->f);
	write_to_file(s, this->f);
	fclose(this->f);
}

void DDB::Delete(const Record &s) {
	if((this->f = fopen(this->filename, "rb+")) == NULL) {
		return;
	}

	seek_from_begin_file(s.id, this->f);
	Record n; n.id = -1;
	write_to_file(n, this->f);
	fclose(this->f);
}

void DDB::Sort() {}
