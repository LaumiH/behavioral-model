#ifndef _BM_DEPARSER_H_
#define _BM_DEPARSER_H_

#include <vector>
#include <string>

#include "phv.h"
#include "packet.h"
#include "event_logger.h"
#include "named_p4object.h"

class Deparser : public NamedP4Object {  
public:
  Deparser(const std::string &name, p4object_id_t id)
    : NamedP4Object(name, id) {}

  void push_back_header(header_id_t header_id) {
    headers.push_back(header_id);
  }

  size_t get_headers_size(const PHV &phv) const;

  void deparse(const PHV &phv, Packet *pkt) const;

private:
  std::vector<header_id_t> headers;
};

#endif