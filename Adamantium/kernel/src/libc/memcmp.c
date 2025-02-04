#include <stdlib.h>

/* Compare two memory values with a set size */
int
memcmp(const void *_str1, const void *_str2, size_t n)
{
    register const uint8_t *s1 = (const uint8_t *)_str1;
    register const uint8_t *s2 = (const uint8_t *)_str2;

    while (n-- > 0)
    {
        if (*s1++ != *s2++)
        {
            return (s1[-1] < s2[-1] ? -1 : 1);
        }
    }
    return (0);
}
