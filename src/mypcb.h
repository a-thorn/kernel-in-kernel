/*
 *  Kernel internal PCB types
 */

#include <linux/types.h>

#define MAX_TASK_NUM		4
#define KERNEL_STACK_SIZE	(1024 * 8)

/* CPU-specific state of this task */
struct Thread {
	uintptr_t ip;
	uintptr_t sp;
};

typedef struct PCB {
	int pid;
	volatile long state;	/* -1 unrunnable, 0 runnable, >0 stopped */
	char stack[KERNEL_STACK_SIZE];
	/* CPU-specific state of this task */
	struct Thread thread;
	uintptr_t task_entry;
	struct PCB *next;
} tPCB;

void my_schedule(void);
