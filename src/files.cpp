#include <cstdio>

#include "files.h"
#include "record.h"

void read(Record &s, FILE *f) {
	fread(&s, sizeof(s), 1, f);
}

void write(const Record &s, FILE *f) {
	fwrite(&s, sizeof(s), 1, f);
}
