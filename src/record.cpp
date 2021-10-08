#include <cstdio>

#include "record.h"

void input(Record &s) {
	printf("id: ");
	scanf("%d", &s.id);

	if (s.id <= 0) {
		return;
	}

	printf("name: ");
	scanf("%s", s.name);
}

void print(const Record &s) {
	if (s.id == -1) {
		printf("Empty record\n");
		return;
	}
	printf("%d, %s\n", s.id, s.name);
}
