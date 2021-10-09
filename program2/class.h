
typedef struct {
    char cnumber[15];
    char ctitle[60];
    char professor[60];
    char cdays[15];
    char ctime[15];
    int no_seats;
} class_t;

typedef struct node_t{
	class_t* cl;
	struct node_t *next;
} node_t;

void readClasses(node_t**);
void queryUser(node_t*);
void parseLine(node_t**, char*);
char askUser();
void BreakUpDayTime(class_t*, char*);
void printClassByNum(node_t*);
void printClassesDay(node_t*);
void printClassesProf(node_t*);
void printOneClass(class_t*);
