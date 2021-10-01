#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

// Record

struct Record {
	int id;
	char name[50];
	void clear() {
		id = 0;
		name = "";
	}
};

void input(Record &d) {
	printf("id: ");
	scanf("%d", &d.id);

	if (d.id <= 0) {
		return;
	}

	printf("name: ");
	scanf("%s", d.name);
}

void print(const Record &d) {
	printf("%d, %s\n", d.id, d.name);
}

// Files

void write(const Record &s, FILE *f) {
	fwrite(&s, sizeof(s), 1, f);
}

void read(Record &s, FILE *f) {
	fread(&s, sizeof(s), 1, f);
}

// DB
// для файла с последовательным доступом

class DB
{
	string filename;
	FILE *f;
public:
	DB(string filename) : filename(filename) {}

	void Find(int key, Record &s) {
		if((f = fopen("db.bin", "rb")) != NULL) {
			read(s, f);
			while(!feof(f) && s.id != key) {
				read(s, f);
			}
			fclose(f);

			if (s.id != key) {
				s.clear();
			}
		}
	}

	void Append(const Record &s);
	void Insert(const Record &s);
	void Update(const Record &s);
	void Delete(const Record &s);
	void Sort();

};

int main()
{
	Record *s;
	DB db = DB("db.bin");
	db.Find(50, s);
	print(s);
	// FILE *f, *fcopy;
	// if((f = fopen("db.bin", "ab")) != NULL) {
	// 	input(s);
	// 	while(s.id > 0) {
	// 		write(s, f);
	// 		input(s);
	// 	}
	// 	fclose(f);
	// }

	// if((f = fopen("db.bin", "rb")) != NULL && (fcopy = fopen("dbcopy.bin", "ab")) != NULL) {
	// 	read(s, f);
	// 	while(!feof(f)) {
	// 		print(s);
	// 		// write(s, fcopy);
	// 		read(s, f);
	// 	}
	// }

	return 0;
}
