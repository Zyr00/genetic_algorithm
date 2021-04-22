#ifndef _TIMETABLE_
#define _TIMETABLE_

#include <stdlib.h>

enum hour_block{ nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen };

typedef struct {
  char *class_number;
  char *unit;
  char *teacher;
  enum hour_block hours;
  short int room;
} lesson;

#endif /* _TIMETABLE_ */
