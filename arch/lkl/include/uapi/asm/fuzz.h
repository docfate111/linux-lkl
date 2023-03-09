#ifndef _UAPIFUZZ_H
#define _UAPIFUZZ_H

#include <linux/types.h>

typedef int(*fp_done_callback)(void);

#define FUZZ_MAX_DEVT 16
struct fuzz_devnode {
   unsigned long devt;
   int type;
   int active;
};

#endif
