#ifndef _TIMETABLE_
#define _TIMETABLE_

#include <stdlib.h>
#include "../includes/genetic.h"

#define TIMETABLE_DEFAULT_POP_SIZE 40
#define TIMETABLE_DEFAULT_GEN_SIZE 25
#define TIMETABLE_DEFAULT_MUTATION 0.015
#define TIMETABLE_DEFAULT_ROOM_SIZE 40
#define TIMETABLE_ROOM_MAX_VALUE 30
#define TIMETABLE_ROOM_MIN_VALUE 10
#define TIMETABLE_DEFAULT_TEACHER_SIZE 40
#define TIMETABLE_DEFAULT_CLASS_SIZE 40
#define TIMETABLE_CLASS_MAX_VALUE 30
#define TIMETABLE_CLASS_MIN_VALUE 10
#define TIMETABLE_HOUR_BLOCK_SIZE 9
#define TIMETABLE_HOUR_BLOCK_DIFERENCE 2

enum hour_block{ nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen };

typedef struct {
  short unsigned int id;
  short unsigned int size_of_class;
} CLASS;

typedef struct {
  short unsigned int id;
  short unsigned int size;
} ROOM;

typedef struct {
  short unsigned int id;
} TEACHER;

typedef struct {
  short unsigned int unit;
  CLASS class_;
  TEACHER teacher;
  ROOM room;
  enum hour_block hours;
} LESSON;

extern ROOM *rooms;
extern TEACHER *teachers;
extern CLASS *classes;
extern size_t rooms_length;
extern size_t teachers_length;
extern size_t classes_length;

void generate_rooms(const size_t, const short unsigned int, const short unsigned int);
void generate_teachers(const size_t);
void generate_classes(const size_t, const short unsigned int, const short unsigned int);
void *timetable_random_genome(const size_t);

void timetable_free(POPULATION *pop);

#endif /* _TIMETABLE_ */
