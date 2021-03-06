/* This file has been modified by H.J. Lu. */

/* This is file READV.C */
/*
** Copyright (C) 1991 DJ Delorie, 24 Kirsten Ave, Rochester NH 03867-2954
**
** This file is distributed under the terms listed in the document
** "copying.dj", available from DJ Delorie at the address above.
** A copy of "copying.dj" should accompany this file; if not, a copy
** should be available from where this file was obtained.  This file
** may not be distributed without a verbatim copy of "copying.dj".
**
** This file is distributed WITHOUT ANY WARRANTY; without even the implied
** warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
**
** Modified by H.J. Lu 1992
*/

#include <sys/types.h>
#include <sys/uio.h>

#ifdef linux
#include <unistd.h>
#endif

int
readv(int handle, const struct iovec *iov, size_t count)
{
  int r, t=0;

  while (count) {
    r = read(handle, iov->iov_base, iov->iov_len);
    if (r < 0)
      return r;
    t += r;
    iov++;
    count--;
  }
  return t;
}
