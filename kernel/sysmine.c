#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "syscall.h"
#include "defs.h"

#include "types.h"
#include "defs.h"
#include "param.h"
#include "stat.h"
#include "proc.h"
#include "fs.h"
#include "file.h"

int sys_chmod(void) {
  char *path;
  int mode;
  
  if (argstr(0, &path) < 0 || argint(1, &mode) < 0) {
    return -1;
  }

  // Obtener el inodo del archivo
  struct inode *ip = namei(path);
  if (ip == 0) {
    return -1; // Archivo no encontrado
  }

  // Modificar los permisos
  ip->permissions = mode;
  iupdate(ip);
  return 0;
}
