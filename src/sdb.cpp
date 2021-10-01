#include <cstring>

#include "sdb.h"
#include "record.h"
#include "files.h"

void SDB::FindWithCopy(int key) {
	if((this->f = fopen(this->filename, "rb")) == NULL) {
		return;
	}
	if((this->fcopy = fopen(this->filename_copy, "wb")) == NULL) {
		fclose(this->f);
		return;
	}

	Record s;
	read_from_file(s, this->f);
	write_to_file(s, this->fcopy);
	while(!feof(this->f) && s.id < key) {
		read_from_file(s, this->f);
		write_to_file(s, this->fcopy);
	}
}

void SDB::FinishCopy() {
	Record s;
	read_from_file(s, this->f);
	write_to_file(s, this->fcopy);
	while(!feof(this->f)) {
		read_from_file(s, this->f);
		write_to_file(s, this->fcopy);
	}

	fclose(this->f);
	fclose(this->fcopy);
}

SDB::SDB(char *filename) : filename(filename) {
	strcat(this->filename_copy, this->filename);
}

void SDB::Find(int key, Record &s) {
	if((f = fopen(this->filename, "rb")) == NULL) {
		return;
	}

	read_from_file(s, f);
	while(!feof(f) && s.id != key) {
		read_from_file(s, f);
	}

	if (s.id != key) {
		s.id = -1;
	}
	fclose(f);
}

void SDB::Append(const Record &s) {
	if((f = fopen(this->filename, "ab")) == NULL) {
		return;
	}

	write_to_file(s, f);
	fclose(f);
}

void SDB::Insert(const Record &s) {
	this->FindWithCopy(s.id);
	write_to_file(s, this->fcopy);
	this->FinishCopy();
}

void SDB::Update(const Record &s) {}
void SDB::Delete(const Record &s) {}
void SDB::Sort() {}
