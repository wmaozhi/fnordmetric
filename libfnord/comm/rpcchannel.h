/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef _FNORD_COMM_RPCCHANNEL_H
#define _FNORD_COMM_RPCCHANNEL_H
#include <functional>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace fnord {
namespace comm {

class RPCChannel {
public:
  virtual ~RPCChannel() {}

};


class LocalRPCChannel : public RPCChannel {
public:

  template <typename ServiceType>
  LocalRPCChannel(ServiceType* service);

  template <class RPCType>
  void call(RPCType* rpc);

  template <typename MethodType>
  void method(MethodType* method);

  //std::unordered_map<std::string>
  //template <class RPCType>
  //void callImpl(RPCType* rpc);

protected:
  void* service_;
  std::unordered_map<std::string, std::function<void (AnyRPC* rpc)>> methods_;
};

} // namespace comm
} // namsepace fnord

#include "rpcchannel_impl.h"
#endif
