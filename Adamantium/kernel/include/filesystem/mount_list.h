#ifndef _FILESYSTEM_MOUNT_LIST_H
#define _FILESYSTEM_MOUNT_LIST_H

#include <stdint.h>

struct mount_list
{
	struct mount_point* mp;
	struct mount_list* next;
};

#endif
