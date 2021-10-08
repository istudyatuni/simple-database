#ifndef FILES_H
#define FILES_H

#include "record.h"

void read(Record &s, FILE *f);
void write(const Record &s, FILE *f);

#endif // FILES_H
