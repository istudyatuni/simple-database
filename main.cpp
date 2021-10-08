#include <cstring>

#include "ddb.h"
#include "record.h"

using namespace std;

int main()
{
	Record s;
	char dbname[] = "db.bin";
	DDB db = DDB(dbname);

	s.id = 1; strcpy(s.name, "one updated");
	db.Write(s);

	s.id = 6; strcpy(s.name, "six");
	db.Write(s);

	s.id = 7; strcpy(s.name, "seven");
	db.Delete(s);

	db.Find(1, s);
	print(s);
	db.Find(6, s);
	print(s);
	db.Find(7, s);
	print(s);

	return 0;
}
