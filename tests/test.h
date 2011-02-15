#ifndef LIBMONGO_CLIENT_TEST_H
#define LIBMONGO_CLIENT_TEST_H 1

#include "bson.h"
#include <stdio.h>
#include <stdlib.h>

static gchar *current_test __attribute__((unused)) = NULL;
static gint current_test_no __attribute__((unused)) = 0;

#ifndef TEST_SERVER_IP
#define TEST_SERVER_IP "127.0.0.1"
#endif

#ifndef TEST_SERVER_IPV6
#define TEST_SERVER_IPV6 "::1"
#endif

#ifndef TEST_SERVER_HOST
#define TEST_SERVER_HOST "localhost"
#endif

#ifndef TEST_SERVER_PORT
#define TEST_SERVER_PORT 27017
#endif

#ifndef TEST_ARBITER_IP
#define TEST_ARBITER_IP "127.0.0.1"
#endif

#ifndef TEST_ARBITER_PORT
#define TEST_ARBITER_PORT 30000
#endif

#ifndef TEST_SERVER_DB
#define TEST_SERVER_DB "test"
#endif

#ifndef TEST_SERVER_COLLECTION
#define TEST_SERVER_COLLECTION "libmongo"
#endif

#define TEST_SERVER_NS TEST_SERVER_DB "." TEST_SERVER_COLLECTION

#define PLAN(b,e) {				\
    printf ("%d..%d\n", b, e);			\
  }

#define TEST(s)					\
  {						\
    current_test = #s;				\
    current_test_no++;				\
    printf ("# %s\n", current_test);		\
  }
#define PASS()					\
  {						\
    printf ("ok %d\n", current_test_no);	\
    current_test = NULL;			\
  }
#define SKIP(s)						\
  {							\
    printf ("ok %d # SKIP %s\n", current_test_no, s);	\
    current_test = NULL;				\
  }

#define SKIP_ALL(s)				\
  {						\
    printf ("1..0 # SKIP %s\n", s);		\
    exit (0);					\
  }

gboolean dump_data (const guint8 *d, gint32 size);
gboolean dump_bson (bson *b);

#endif
