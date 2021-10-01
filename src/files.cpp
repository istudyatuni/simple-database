#include <cstdio>

#include "files.h"
#include "record.h"

void read_from_file(Record &s, FILE *f) {
	fread(&s, sizeof(s), 1, f);
}

void write_to_file(const Record &s, FILE *f) {
	fwrite(&s, sizeof(s), 1, f);
}
