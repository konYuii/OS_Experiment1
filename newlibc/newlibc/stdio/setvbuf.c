/* This is file SETVBUF.C */
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
*/

#include <stdio.h>

#ifdef linux
#include <stdlib.h>
#endif

int setvbuf(FILE *f, char *buf, int type, int len)
{
  int mine=0;
  if (!f)
    return -1;
  fflush(f);
  switch (type)
  {
    case _IOFBF:
    case _IOLBF:
      if (len <= 0)
        return -1;
      if (buf == 0)
      {
        buf = (char *)malloc(len);
        if (buf == 0)
          return -1;
        mine = 1;
      }
      setbuffer(f, NULL, 0);
      f->_flag &= ~_IONBF;
      f->_flag |= type;
      if (mine)
        f->_flag |= _IOMYBUF;
      f->_base = buf;
      f->_bufsiz = len;
      return 0;
    case _IONBF:
      setbuffer(f, NULL, 0);
      return 0;
    default:
      return -1;
  }
}
