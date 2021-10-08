#ifndef RECORD_H
#define RECORD_H

struct Record {
	int id;
	char name[50];
};

void input(Record &s);
void print(const Record &s);

#endif // RECORD_H
