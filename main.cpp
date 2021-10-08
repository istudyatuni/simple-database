#include <cstring>

#include "sdb.h"
#include "record.h"

using namespace std;

int main()
{
	Record s;
	char dbname[] = "db.bin";
	SDB db = SDB(dbname);

	s.id = 6; strcpy(s.name, "six");
	db.Append(s);
	db.Find(6, s);
	print(s);

	s.id = 7; strcpy(s.name, "seven");
	db.Append(s);
	db.Find(7, s);
	print(s);

	return 0;
}
