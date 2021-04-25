#include "../includes/timetable.h"
#include "../includes/utils.h"

ROOM *rooms;
TEACHER *teachers;
CLASS *classes;
UNIT *units;
size_t rooms_length, teachers_length, classes_length, units_length;

/**
 * @brief generate rooms
 * @param size the number of rooms to generate
 * @param min the min number of students that fit in the room
 * @param max the max number of students that fit in the room
 */
void generate_rooms(const size_t size, const unsigned int min, const unsigned int max) {
  size_t i;

  if (size <= 0) return;

  rooms_length = size;
  rooms = malloc(sizeof(ROOM) * size);
  if (rooms == NULL) return;

  for (i = 0; i < size; i++) {
    rooms[i].id = i + 1;
    rooms[i].size = min + random_int(max);
  }
}

/**
 * @brief generate teachers
 * @param size the number of teachers to generate
 */
void generate_teachers(const size_t size) {
  size_t i;

  if (size <= 0) return;

  teachers_length = size;
  teachers = malloc(sizeof(TEACHER) * size);
  if (teachers == NULL) return;

  for (i = 0; i < size; i++) teachers[i].id = i + 1;
}

/**
 * @brief generate classes
 * @param size the number of classes to generate
 * @param min the min number that a class can have of students
 * @param max the max number that a calss can have of students
 */
void generate_classes(const size_t size, const unsigned int min, const unsigned int max) {
  size_t i;

  if (size <= 0) return;

  classes_length = size;
  classes = malloc(sizeof(CLASS) * size);
  if (classes == NULL) return;

  for (i = 0; i < size; i++) {
    classes[i].id = i + 1;
    classes[i].size_of_class = min + random_int(max);
  }
}

/**
 * @brief generate units
 * @param size the total number of units to generate
 */
void generate_units(const size_t size) {
  size_t i;

  if (size <= 0) return;

  units_length = size;
  units = malloc(sizeof(UNIT) * size);
  if (units == NULL) return;

  for (i = 0; i < size; i++)
    units[i].id = random_int(size);

}

/**
 * @brief generate random genome for the timetable problem
 * @param gen_size the length of the genome for the timetable problem
 * @return a void pointer of the lessons
 */
void *timetable_random_genome(const size_t gen_size) {
  size_t i;
  LESSON *lessons = NULL;

  if (gen_size <= 0) return NULL;

  lessons = malloc(sizeof(LESSON) * gen_size);
  if (lessons == NULL) return NULL;

  for (i = 0; i < gen_size; i++) {
    lessons[i].unit = units[random_int(units_length)];
    lessons[i].room = rooms[random_int(rooms_length)];
    lessons[i].teacher = teachers[random_int(rooms_length)];
    lessons[i].class_ = classes[random_int(classes_length)];
    lessons[i].hours = random_int(TIMETABLE_HOUR_BLOCK_SIZE - TIMETABLE_HOUR_BLOCK_DIFERENCE) + TIMETABLE_HOUR_BLOCK_DIFERENCE;
  }

  return lessons;
}

/**
 * @brief free timetable from memory
 */
void timetable_free(POPULATION *pop) {
  free((LESSON *) pop->genes);
  free(pop);
  free(rooms);
  free(teachers);
  free(classes);
  free(units);
}
