#include <cstdio>
#include <cstdlib>

using namespace std;

struct rec {
	int id;
	char name[50];
};

void input(rec &d) {
	printf("id: ");
	scanf("%d", &d.id);

	if (d.id <= 0) {
		return;
	}

	printf("name: ");
	scanf("%s", d.name);
}

void print(const rec &d) {
	printf("%d, %s\n", d.id, d.name);
}

int main()
{
	rec s;
	FILE *f, *fcopy;
	if((f = fopen("db.bin", "ab")) != NULL) {
		input(s);
		while(s.id > 0) {
		    fwrite(&s, sizeof(s), 1, f);
			input(s);
		}
		fclose(f);
	}

	if((f = fopen("db.bin", "rb")) != NULL && (fcopy = fopen("dbcopy.bin", "ab")) != NULL) {
		fread(&s, sizeof(s), 1, f);
		while(!feof(f)) {
			print(s);
			fwrite(&s, sizeof(s), 1, fcopy);
			fread(&s, sizeof(s), 1, f);
		}
	}

	return 0;
}
