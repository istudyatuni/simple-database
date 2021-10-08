#ifndef FILES_H
#define FILES_H

#include "record.h"

void read_from_file(Record &s, FILE *f);
void write_to_file(const Record &s, FILE *f);

void seek_from_begin_file(int offset, FILE *f);

#endif // FILES_H
