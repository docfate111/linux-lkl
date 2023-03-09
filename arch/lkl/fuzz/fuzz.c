#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/pci.h>
#include <linux/printk.h>
#include <linux/interrupt.h>
#include <linux/types.h>
#include <linux/io.h>
#include <linux/dma-mapping.h>
#include <linux/scatterlist.h>
#include <linux/mm.h>
#include <uapi/asm/fuzz.h>
#include <asm/host_ops.h>
#include "fuzz.h"

static void kasan_test(void) {
   int i;
   int *ptr;
   ptr = kmalloc(sizeof(int)*16, GFP_KERNEL);
   for(i=0; i<17; i++) {
      pr_err("%s ptr[%d] = %d\n", __FUNCTION__, i, ptr[i]);
   }
}

//void run_irq(int irq);
SYSCALL_DEFINE1(fuzz_trigger_irq, int, irq)
{
	//run_irq(irq);
   //return 0;
   return lkl_trigger_irq(irq);
}
