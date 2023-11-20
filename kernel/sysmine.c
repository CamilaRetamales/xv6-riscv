#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "syscall.h"
#include "defs.h"

int getppid() {
    struct proc *my_proc = myproc();
    return my_proc->parent->pid;
}

int getancestor(int a){
    struct proc *p = myproc(); //puntero que apunta al proceso actual
    int pid; //inicializamos variable
    int c = 0; //contador

//    printf("%d\n",a);
//    printf("%d\n",p);

    if (a == 0){
        pid = p -> pid;
    }


    while(p != 0 && c<a) //el pariente tiene que ser distinto de cero y el contador tiene que ser menor para el tamaño de los parientes
    {
        //printf("%d\n",p->pid);
        p = p->parent;
        c = c+1;
    }

    //printf("%d\n",c);

    if (p != 0){
        pid = p->pid; //obtenemos el ultimo pariente 
        
    }

    else{
        
        pid = -1; //se sobre pasa por lo que tiene que retornar -1
    }
    
 return pid; //retorna el pariente pedido
}
int sys_getppid() {
    return getppid(); //retornamos la funcion

}

int sys_getancestor() {
    int g; //inicializamo variable
    argint(0, &g); //pedimos el nùmero en forma de puntero 
    return getancestor(g); //retornamos la funcion
}
