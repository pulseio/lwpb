#include "protoc_gen_lwpb.h"

#include <google/protobuf/compiler/plugin.h>
#include "lwpb_code_generator.h"

int main(int argc, char **argv) {
  LWPBCodeGenerator generator;
  return google::protobuf::compiler::PluginMain(argc, argv, &generator);
}
