#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int systemtime = 0;

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_waitAux(void)
{
  //int system_time = argint(0,system_time);
  char *ptr;
  argptr(0, &ptr, sizeof(int));
  // seu código aqui
  int *system_time = (int *)ptr;
  return waitAux(system_time);
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_date(void)
{
  char *ptr;
  argptr(0, &ptr, sizeof(struct rtcdate*));
  // seu código aqui
  rtcdate *date_var = (rtcdate *)ptr;
  cmostime(date_var);
  return 0;
}

int
sys_time(void){
  return 0;
}

int
sys_testes(void){
  return 0;
}

int
sys_setprio(void){
  /*char *ptr1;
  char *ptr2;
  argptr(0, &ptr1, 2*sizeof(int));
  argptr(1, &ptr2, 2*sizeof(int));
  // seu código aqui
  int *priority = (int *)ptr1;
  int *p_id = (int *)ptr2;*/

  int priority;
  int p_id;

  argint(0, &priority);
  argint(1, &p_id);

  cprintf("priority %d, p_id %d ", priority, p_id);
  setprio(priority,p_id);
  return 0;
}

int sys_run(void){
  return 0;
}
