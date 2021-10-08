#include "sdb.h"
#include "record.h"

using namespace std;

int main()
{
	Record s;
	char dbname[] = "db.bin";
	SDB db = SDB(dbname);
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
