#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "user.h"

int main(void) {
  char *filename = "miarchivo.txt";
  int new_mode = RW;

  if (chmod(filename, new_mode) < 0) {
    printf(1, "Error al cambiar los permisos de %s\n", filename);
  } else {
    printf(1, "Permisos de %s cambiados con éxito\n", filename);
  }

  exit();
}