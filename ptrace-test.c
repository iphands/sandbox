#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>

void print_ur_struct(struct user_regs_struct regs);

void print_ur_struct(struct user_regs_struct regs)
{
  printf("\nstruct user_regs_struct\n");
  printf("{\n");
  printf("  long int ebx; (0x%x)\n", (unsigned int) regs.ebx);
  printf("  long int ecx; (0x%x)\n", (unsigned int) regs.ecx);
  printf("  long int edx; (0x%x)\n", (unsigned int) regs.edx);
  printf("  long int esi; (0x%x)\n", (unsigned int) regs.esi);
  printf("  long int edi; (0x%x)\n", (unsigned int) regs.edi);
  printf("  long int ebp; (0x%x)\n", (unsigned int) regs.ebp);
  printf("  long int eax; (0x%x)\n", (unsigned int) regs.eax);
  printf("  long int xds; (0x%x)\n", (unsigned int) regs.xds);
  printf("  long int xes; (0x%x)\n", (unsigned int) regs.xes);
  printf("  long int xfs; (0x%x)\n", (unsigned int) regs.xfs);
  printf("  long int xgs; (0x%x)\n", (unsigned int) regs.xgs);
  printf("  long int orig_eax; (0x%x)\n", (unsigned int) regs.orig_eax);
  printf("  long int eip; (0x%x)\n", (unsigned int) regs.eip);
  printf("  long int xcs; (0x%x)\n", (unsigned int) regs.xcs);
  printf("  long int eflags; (0x%x)\n", (unsigned int) regs.eflags);
  printf("  long int esp; (0x%x)\n", (unsigned int) regs.esp);
  printf("  long int xss; (0x%x)\n", (unsigned int) regs.xss);
  printf("};\n\n");
  return;
}

int main(int argc, char ** argv)
{

  if (argc < 2) {
    printf("Please pass in a pid number\n");
    return(1);
  }
  
  pid_t pid = atoi(argv[1]);
  printf("Attaching to pid %d\n", (int)pid);

  long data = ptrace(PTRACE_ATTACH, pid, 0, NULL);
  printf("attach return: %d\n", (int)data);
  if (data == -1) {
    printf("Failed to attach!\n");
    return(1);
  }

  struct user_regs_struct regs;
  ptrace(PTRACE_GETREGS, pid, NULL, &regs);
  print_ur_struct(regs);

  for (int i = 0; i < 10000; i++) {
    data = ptrace(PTRACE_PEEKDATA, pid, regs.ebx + i, NULL);

    if ( (data == -1) || (data == 0) ) {
      continue;
    }

    //printf("int[%d]: %ld\n", i, data);
    printf("hex[%d]: %x\n", i, (unsigned int) data);
    //printf("string[%d]: %c\n", i, (char) data);
    //printf("%c", (char) data);
    if ((char) data == '\0') {
      //printf("\n[%d]", i);
    }
  }
  printf("\n");

  ptrace(PTRACE_DETACH, pid, NULL, NULL);

  return(0);
}
