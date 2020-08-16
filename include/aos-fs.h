#ifndef _AOS_FILE_SYSTEM_
#define _AOS_FILE_SYSTEM_

#define KERNEL32    1

#include "types.h"
#include "string.h"
#include "aos-defs.h"
#include "device.h"
#include "vfs.h"

#define AOS_ROOT_DIRNAME        "$0://root/"
#define AOS_FILE_SYSTEM_NAME    "AOS32"

#if defined(__cplusplus)
extern "C" {
#endif

struct aos_file 
{
    char fname[64];
    string extension;
    string fpath;
    uint8_t readonly;
    uint8_t hidden;
    uint32_t filesize;
    uint32_t permission_level;
    // time_t *creation_date;
    // time_t *creation_time;
};

struct aos_directory
{
    string fs_name;
    string root_dir;
    uint32_t permission_level;
    // time_t *creation_date;
    // time_t *creation_time;
};

typedef struct aos_file         File_t;
typedef struct aos_directory    Directory_t;

extern void aosfs_init(string fs_name);

#if defined(__cplusplus)
}
#endif

#endif
