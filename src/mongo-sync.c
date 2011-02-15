/* mongo-sync.c - libmongo-client synchronous wrapper API
 * Copyright 2011 Gergely Nagy <algernon@balabit.hu>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mongo.h"

gboolean
mongo_sync_cmd_update (mongo_connection *conn,
		       const gchar *ns,
		       gint32 flags, const bson *selector,
		       const bson *update)
{
  mongo_packet *p;
  gint32 rid;

  if (!conn)
    return FALSE;

  rid = mongo_connection_get_requestid (conn) + 1;

  p = mongo_wire_cmd_update (rid, ns, flags, selector, update);
  if (!p)
    return FALSE;

  if (!mongo_packet_send (conn, p))
    {
      mongo_wire_packet_free (p);
      return FALSE;
    }
  mongo_wire_packet_free (p);
  return TRUE;
}

gboolean
mongo_sync_cmd_insert (mongo_connection *conn,
		       const char *ns,
		       const bson *doc)
{
  mongo_packet *p;
  gint32 rid;

  if (!conn)
    return FALSE;

  rid = mongo_connection_get_requestid (conn) + 1;

  p = mongo_wire_cmd_insert (rid, ns, doc, NULL);
  if (!p)
    return FALSE;

  if (!mongo_packet_send (conn, p))
    {
      mongo_wire_packet_free (p);
      return FALSE;
    }
  mongo_wire_packet_free (p);
  return TRUE;
}
