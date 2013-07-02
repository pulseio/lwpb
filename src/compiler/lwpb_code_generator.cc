#include "lwpb_code_generator.h"
#include <google/protobuf/stubs/strutil.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/printer.h>

string StripProto(const string& filename) {
  const char* suffix = HasSuffixString(filename, ".protodevel")
      ? ".protodevel" : ".proto";
  return StripSuffixString(filename, suffix);
}

string ModuleName(const string& filename) {
  string basename = StripProto(filename);
  StripString(&basename, "-", '_');
  StripString(&basename, "/", '.');
  return basename + ".pb";
}

string ModuleFileName(const string& filename) {
  string basename = StripProto(filename);
  StripString(&basename, "-", '_');
  return basename + ".pb";
}

// Returns the name of all containing types for descriptor,
// in order from outermost to innermost, followed by descriptor's
// own name.  Each name is separated by |separator|.
template <typename DescriptorT>
string NamePrefixedWithNestedTypes(const DescriptorT& descriptor,
                                   const string& separator) {
  string name = descriptor.name();
  for (const Descriptor* current = descriptor.containing_type();
       current != NULL; current = current->containing_type()) {
    name = current->name() + separator + name;
  }
  return name;
}

// Returns a Python literal giving the default value for a field.
// If the field specifies no explicit default value, we'll return
// the default default value for the field type (zero for numbers,
// empty string for strings, empty list for repeated fields, and
// None for non-repeated, composite fields).
//
// TODO(robinson): Unify with code from
// //compiler/cpp/internal/primitive_field.cc
// //compiler/cpp/internal/enum_field.cc
// //compiler/cpp/internal/string_field.cc
string StringifyDefaultValue(const FieldDescriptor& field) {
  if (field.is_repeated()) {
    return ".def.null = 0";
  }

  switch (field.cpp_type()) {
    case FieldDescriptor::CPPTYPE_INT32:
      return ".def.int32 = " + SimpleItoa(field.default_value_int32());
    case FieldDescriptor::CPPTYPE_UINT32:
      return ".def.uint32 = " + SimpleItoa(field.default_value_uint32());
    case FieldDescriptor::CPPTYPE_INT64:
      return ".def.int64 = " + SimpleItoa(field.default_value_int64());
    case FieldDescriptor::CPPTYPE_UINT64:
      return ".def.uint64 = " + SimpleItoa(field.default_value_uint64());
    case FieldDescriptor::CPPTYPE_DOUBLE:
      return ".def.double_ = " + SimpleDtoa(field.default_value_double());
    case FieldDescriptor::CPPTYPE_FLOAT:
      return ".def.float_ = " + SimpleFtoa(field.default_value_double());
    case FieldDescriptor::CPPTYPE_BOOL:
      return ".def.boolean = " + SimpleItoa(field.default_value_bool() ? 1 : 0);
    case FieldDescriptor::CPPTYPE_ENUM:
      return ".def.int32 = " + SimpleItoa(field.default_value_enum()->number());
    case FieldDescriptor::CPPTYPE_STRING:
      return ".def.string.str = \"" + CEscape(field.default_value_string()) + "\"";
    case FieldDescriptor::CPPTYPE_MESSAGE:
      return ".def.null = 0";
  }
  // (We could add a default case above but then we wouldn't get the nice
  // compiler warning when a new type is added.)
  GOOGLE_LOG(FATAL) << "Not reached.";
  return "";
}

LWPBCodeGenerator::LWPBCodeGenerator() : file_(NULL) {}
LWPBCodeGenerator::~LWPBCodeGenerator() {}

bool LWPBCodeGenerator::Generate(const FileDescriptor * file,
                                 const string & parameter,
                                 compiler::GeneratorContext * generator_context,
                                 string * error) const {

  file_ = file;
  string filename = ModuleFileName(file->name());

  scoped_ptr<io::ZeroCopyOutputStream> h_output(generator_context->Open(filename + ".h"));
  GOOGLE_CHECK(h_output.get());
  io::Printer h_printer(h_output.get(), '$');
  h_printer_ = &h_printer;
  
  scoped_ptr<io::ZeroCopyOutputStream> c_output(generator_context->Open(filename + ".c"));
  GOOGLE_CHECK(c_output.get());
  io::Printer c_printer(c_output.get(), '$');
  c_printer_ = &c_printer;
  
  
  CreateEnumList();
  CreateMessageList();
  
  PrintHeader();
  
  PrintImports();
  
  PrintEnumDescriptors();
  PrintMessageDescriptors();
  PrintServiceDescriptors();
  
  PrintFooter();
  
  return (!h_printer.failed()) && (!c_printer.failed());
  //  return true;

}

// Returns the name of the include guard.
string LWPBCodeGenerator::FileDescriptorIncludeGuard(
    const FileDescriptor& descriptor) const {
  string name = StripProto(descriptor.name());
  StripString(&name, "-", '_');
  StripString(&name, "/", '.');
  name = "__" + name + "_PB2_H__";
  UpperString(&name);
  return name;
}

// Returns the name of the message array.
string LWPBCodeGenerator::FileDescriptorMessageArray(
    const FileDescriptor& descriptor) const {
  string package = StringReplace(descriptor.package(), ".", "_", true);
  string name = StripProto(descriptor.name());
  LowerString(&name);
  name = "lwpb_messages_" + package + "_" + name;
  LowerString(&name);
  return name;
}

// Returns the name of the service array.
string LWPBCodeGenerator::FileDescriptorServiceArray(
    const FileDescriptor& descriptor) const {
  string package = StringReplace(descriptor.package(), ".", "_", true);
  string name = StripProto(descriptor.name());
  LowerString(&name);
  name = "lwpb_services_" + package + "_" + name;
  LowerString(&name);
  return name;
}

// Returns the name of the message descriptor.
string LWPBCodeGenerator::MessageDescriptorId(
    const Descriptor& descriptor) const {
  string name = descriptor.full_name();
  name = StringReplace(name, ".", "_", true);
  //UpperString(&name);
  return name;
}

// Returns the name of the message descriptor pointer.
string LWPBCodeGenerator::MessageDescriptorPtr(
    const Descriptor& descriptor) const {
  string array = FileDescriptorMessageArray(*descriptor.file());
  string ptr = "(&" + array + "[" + SimpleItoa(GetMessageIndex(&descriptor)) + "])";
  return ptr;
}

// Returns the name of the message's field array.
string LWPBCodeGenerator::MessageDescriptorFieldArray(
    const Descriptor& descriptor) const {
  string name = descriptor.full_name();
  name = StringReplace(name, ".", "_", true);
  name = "lwpb_fields_" + name;
  LowerString(&name);
  return name;
}

// Returns the name of the field descriptor.
string LWPBCodeGenerator::FieldDescriptorId(
    const FieldDescriptor& descriptor) const {
  string name = descriptor.full_name();
  name = StringReplace(name, ".", "_", true);
  return name;
}

// Returns the name of the field descriptor pointer.
string LWPBCodeGenerator::FieldDescriptorPtr(
    const FieldDescriptor& descriptor) const {
  string array = MessageDescriptorFieldArray(*descriptor.containing_type());
  string ptr = "(&" + array + "[" + SimpleItoa(descriptor.index()) + "])";
  return ptr;
}

string LWPBCodeGenerator::FieldDescriptorOptLabel(const FieldDescriptor& field) const {
  switch (field.label()) {
  case FieldDescriptor::LABEL_OPTIONAL: return "LWPB_OPTIONAL";
  case FieldDescriptor::LABEL_REQUIRED: return "LWPB_REQUIRED";
  case FieldDescriptor::LABEL_REPEATED: return "LWPB_REPEATED";
  }
    
  GOOGLE_LOG(FATAL) << "Not reached.";
  return "";
}

string LWPBCodeGenerator::FieldDescriptorOptTyp(const FieldDescriptor& field) const {
  switch (field.type()) {
  case FieldDescriptor::TYPE_DOUBLE:    return "LWPB_DOUBLE";
  case FieldDescriptor::TYPE_FLOAT:     return "LWPB_FLOAT";
  case FieldDescriptor::TYPE_INT32:     return "LWPB_INT32";
  case FieldDescriptor::TYPE_INT64:     return "LWPB_INT64";
  case FieldDescriptor::TYPE_UINT32:    return "LWPB_UINT32";
  case FieldDescriptor::TYPE_UINT64:    return "LWPB_UINT64";
  case FieldDescriptor::TYPE_SINT32:    return "LWPB_SINT32";
  case FieldDescriptor::TYPE_SINT64:    return "LWPB_SINT64";
  case FieldDescriptor::TYPE_FIXED32:   return "LWPB_FIXED32";
  case FieldDescriptor::TYPE_FIXED64:   return "LWPB_FIXED64";
  case FieldDescriptor::TYPE_SFIXED32:  return "LWPB_SFIXED32";
  case FieldDescriptor::TYPE_SFIXED64:  return "LWPB_SFIXED64";
  case FieldDescriptor::TYPE_BOOL:      return "LWPB_BOOL";
  case FieldDescriptor::TYPE_STRING:    return "LWPB_STRING";
  case FieldDescriptor::TYPE_BYTES:     return "LWPB_BYTES";
  // TODO: we don't support groups
  case FieldDescriptor::TYPE_GROUP:     return "LWPB_GROUP";
  case FieldDescriptor::TYPE_MESSAGE:   return "LWPB_MESSAGE";
  case FieldDescriptor::TYPE_ENUM:      return "LWPB_ENUM";
  }
  
  GOOGLE_LOG(FATAL) << "Not reached.";
  return "";
}

string LWPBCodeGenerator::FieldDescriptorOptFlags(const FieldDescriptor& field) const {
  string flags = "0";
  if (field.has_default_value())
    flags += " | LWPB_HAS_DEFAULT";
  if (field.options().packed())
    flags += " | LWPB_IS_PACKED";
  if (field.options().deprecated())
    flags += " | LWPB_IS_DEPRECATED";
  
  return flags;
}

// Returns the name of the field descriptor.
string LWPBCodeGenerator::ServiceDescriptorId(
    const ServiceDescriptor& descriptor) const {
  string name = descriptor.full_name();
  name = StringReplace(name, ".", "_", true);
  return name;
}

// Returns the name of the service descriptor pointer.
string LWPBCodeGenerator::ServiceDescriptorPtr(
    const ServiceDescriptor& descriptor) const {
  string array = FileDescriptorServiceArray(*descriptor.file());
  string ptr = "(&" + array + "[" + SimpleItoa(descriptor.index()) + "])";
  return ptr;
}

// Returns the name of the service's method array.
string LWPBCodeGenerator::ServiceDescriptorMethodArray(
    const ServiceDescriptor& descriptor) const {
  string name = descriptor.full_name();
  name = StringReplace(name, ".", "_", true);
  name = "lwpb_methods_" + name;
  LowerString(&name);
  return name;
}

string LWPBCodeGenerator::MethodDescriptorId(
    const MethodDescriptor& descriptor) const {
  string name = descriptor.full_name();
  name = StringReplace(name, ".", "_", true);
  return name;
}

string LWPBCodeGenerator::MethodDescriptorPtr(
    const MethodDescriptor& descriptor) const {
  string array = ServiceDescriptorMethodArray(*descriptor.service());
  string ptr = "(&" + array + "[" + SimpleItoa(descriptor.index()) + "])";
  return ptr;
}

// Creates a flat vector |enums| of all enum descriptors.
void LWPBCodeGenerator::CreateEnumList() const {
  for (int i = 0; i < file_->enum_type_count(); ++i)
    enums_.push_back(file_->enum_type(i));
  for (int i = 0; i < file_->message_type_count(); ++i)
    AddNestedEnums(*file_->message_type(i));
}

// Adds all nested enum descriptors to the |enums| vector.
void LWPBCodeGenerator::AddNestedEnums(
    const Descriptor& containing_descriptor) const {
  for (int i = 0; i < containing_descriptor.enum_type_count(); ++i)
    enums_.push_back(containing_descriptor.enum_type(i));
  for (int i = 0; i < containing_descriptor.nested_type_count(); ++i)
    AddNestedEnums(*containing_descriptor.nested_type(i));
}

// Creates a flat vector |messages| of all message descriptors.
void LWPBCodeGenerator::CreateMessageList() const {
  for (int i = 0; i < file_->message_type_count(); ++i)
    messages_.push_back(file_->message_type(i));
  for (int i = 0; i < file_->message_type_count(); ++i)
    AddNestedMessages(*file_->message_type(i));
}

// Adds all nested message descriptors to the |messages| vector.
void LWPBCodeGenerator::AddNestedMessages(
    const Descriptor& containing_descriptor) const {
  for (int i = 0; i < containing_descriptor.nested_type_count(); ++i)
    messages_.push_back(containing_descriptor.nested_type(i));
  for (int i = 0; i < containing_descriptor.nested_type_count(); ++i)
    AddNestedMessages(*containing_descriptor.nested_type(i));
}

// Returns the index of a message descriptor in the flat vector |messages_|.
int LWPBCodeGenerator::GetMessageIndex(const Descriptor* message_descriptor) const {
  return distance(messages_.begin(), find(messages_.begin(), messages_.end(), message_descriptor)); 
}


void LWPBCodeGenerator::PrintHeader() const {
  // Print .h header
  {
    map<string, string> m;
    m["guard"] = FileDescriptorIncludeGuard(*file_);
    h_printer_->Print(m,
        "// Generated by the protocol buffer compiler.  DO NOT EDIT!\n"
        "\n"
        "#ifndef $guard$\n"
        "#define $guard$\n"
        "\n"
        "#include <lwpb/lwpb.h>\n"
        "\n");
  }
  // Print .c header
  {
    map<string, string> m;
    m["include"] = ModuleFileName(file_->name()) + ".h";
    c_printer_->Print(m,
        "// Generated by the protocol buffer compiler.  DO NOT EDIT!\n"
        "\n"
        "#include <lwpb/lwpb.h>\n"
        "\n"
        "#include \"$include$\"\n"
        "\n");
  }
}

void LWPBCodeGenerator::PrintFooter() const {
  // Print .h footer
  {
    map<string, string> m;
    m["guard"] = FileDescriptorIncludeGuard(*file_);
    h_printer_->Print(m,
        "#endif // $guard$\n");
  }
  // Print .c footer
  {
  }
}

// Prints Python imports for all modules imported by |file|.
void LWPBCodeGenerator::PrintImports() const {
  for (int i = 0; i < file_->dependency_count(); ++i) {
    string module_name = ModuleFileName(file_->dependency(i)->name()) + ".h";
    h_printer_->Print("#include \"$module$\"\n", "module", module_name);
  }
  h_printer_->Print("\n");
}

void LWPBCodeGenerator::PrintEnumDescriptors() const {
  for (int i = 0; i < enums_.size(); ++i)
    PrintEnumDescriptor(*enums_[i]);
}

void LWPBCodeGenerator::PrintEnumDescriptor(
    const EnumDescriptor& enum_descriptor) const {
  string enum_name = NamePrefixedWithNestedTypes(enum_descriptor, ".");
  h_printer_->Print("// '$name$' enumeration values\n", "name", enum_name);

  for (int i = 0; i < enum_descriptor.value_count(); ++i) {
    const EnumValueDescriptor &value_descriptor = *enum_descriptor.value(i);
    string name = enum_descriptor.full_name() + "." + value_descriptor.name();
    name = StringReplace(name, ".", "_", true);
    
    UpperString(&name);
    string number = SimpleItoa(value_descriptor.number());
    h_printer_->Print("#define $name$ $number$\n",
                      "name", name, "number", number);
  }
  h_printer_->Print("\n");
}

void LWPBCodeGenerator::PrintMessageDescriptors() const {
  // Print reference to message array
  string array_name = FileDescriptorMessageArray(*file_);
  h_printer_->Print("extern const struct lwpb_msg_desc $array$[];\n",
                    "array", array_name);
  h_printer_->Print("\n");
    
  // Print message id's
  h_printer_->Print("// Message descriptor pointers\n");
  for (int i = 0; i < messages_.size(); ++i) {
    string id = MessageDescriptorId(*messages_[i]);
    string ptr = MessageDescriptorPtr(*messages_[i]);
    h_printer_->Print("#define $id$ $ptr$\n", "id", id, "ptr", ptr);
  }
  h_printer_->Print("\n");
    
  // Print field descriptions
  for (int i = 0; i < messages_.size(); ++i)
    PrintDescriptorFields(*messages_[i]);
  
  // Print message descriptions
  c_printer_->Print("// Message descriptors\n");
  c_printer_->Print("const struct lwpb_msg_desc $name$[] = {\n", "name", array_name);
  for (int i = 0; i < messages_.size(); ++i) {
    map<string, string> m;
    m["num_fields"] = SimpleItoa(messages_[i]->field_count());
    m["fields"] = MessageDescriptorFieldArray(*messages_[i]);
    m["name"] = messages_[i]->name();
    c_printer_->Print(m,
        "    {\n"
        "        .num_fields = $num_fields$,\n"
        "        .fields = $fields$,\n"
        "#if LWPB_MESSAGE_NAMES\n"
        "        .name = \"$name$\",\n"
        "#endif\n"
        "    },\n");
  }
  c_printer_->Print("};\n");
  c_printer_->Print("\n");
}

void LWPBCodeGenerator::PrintDescriptorFields(
    const Descriptor& message_descriptor) const {
  // Print reference to field array
  string array_name = MessageDescriptorFieldArray(message_descriptor);
  h_printer_->Print("extern const struct lwpb_field_desc $array$[];\n",
                    "array", array_name);
  h_printer_->Print("\n");
    
  // Print field id's
  string message_name = message_descriptor.name();
  h_printer_->Print("// '$name$' field descriptor pointers\n", "name", message_name);
  
  for (int i = 0; i < message_descriptor.field_count(); ++i) {
    const FieldDescriptor &field_descriptor = *message_descriptor.field(i);
    string id = FieldDescriptorId(field_descriptor);
    string ptr = FieldDescriptorPtr(field_descriptor);
    h_printer_->Print("#define $id$ $ptr$\n", "id", id, "ptr", ptr);
  }
  h_printer_->Print("\n");
  
  // Print field descriptor array
  c_printer_->Print("// '$name$' field descriptors\n", "name", message_name);
  c_printer_->Print("const struct lwpb_field_desc $name$[] = {\n", "name", array_name);
  for (int i = 0; i < message_descriptor.field_count(); ++i) {
    const FieldDescriptor &field_descriptor = *message_descriptor.field(i);
    map <string, string> m;
    m["number"] = SimpleItoa(field_descriptor.number());
    m["label"] = FieldDescriptorOptLabel(field_descriptor);
    m["typ"] = FieldDescriptorOptTyp(field_descriptor);
    m["flags"] = FieldDescriptorOptFlags(field_descriptor);
    m["msg_desc"] = field_descriptor.type() == FieldDescriptor::TYPE_MESSAGE ?
                    MessageDescriptorId(*field_descriptor.message_type()) : "0";
    m["name"] = field_descriptor.name();
    m["default"] = StringifyDefaultValue(field_descriptor);
    c_printer_->Print(m,
        "    {\n"
        "        .number = $number$,\n"
        "        .opts.label = $label$,\n"
        "        .opts.typ = $typ$,\n"
        "        .opts.flags = $flags$,\n"
        "        .msg_desc = $msg_desc$,\n"
        "#if LWPB_FIELD_NAMES\n"
        "        .name = \"$name$\",\n"
        "#endif\n"
        "#if LWPB_FIELD_DEFAULTS\n"
        "        $default$,\n"
        "#endif\n"
        "    },\n");
  }
  c_printer_->Print("};\n");
  c_printer_->Print("\n");
}

void LWPBCodeGenerator::PrintServiceDescriptors() const {
  // Print reference to serivce array
  string array_name = FileDescriptorServiceArray(*file_);
  h_printer_->Print("extern const struct lwpb_service_desc $array$[];\n",
                    "array", array_name);
  h_printer_->Print("\n");
      
  // Print service id's
  h_printer_->Print("// Service descriptor pointers\n");
  for (int i = 0; i < file_->service_count(); ++i) {
    const ServiceDescriptor &descriptor = *file_->service(i);
    string id = ServiceDescriptorId(descriptor);
    string ptr = ServiceDescriptorPtr(descriptor);
    h_printer_->Print("#define $id$ $ptr$\n", "id", id, "ptr", ptr);
  }
  h_printer_->Print("\n");
  
  // Print method descriptions
  for (int i = 0; i < file_->service_count(); ++i)
    PrintServiceMethods(*file_->service(i));
  
  // Print service descriptions
  c_printer_->Print("// Service descriptors\n");
  c_printer_->Print("const struct lwpb_service_desc $name$[] = {\n", "name", array_name);
  for (int i = 0; i < file_->service_count(); ++i) {
    const ServiceDescriptor &descriptor = *file_->service(i);
    map<string, string> m;
    m["num_methods"] = SimpleItoa(descriptor.method_count());
    m["methods"] = ServiceDescriptorMethodArray(descriptor);
    m["name"] = descriptor.name();
    c_printer_->Print(m,
        "    {\n"
        "        .num_methods = $num_methods$,\n"
        "        .methods = $methods$,\n"
        "#if LWPB_SERVICE_NAMES\n"
        "        .name = \"$name$\",\n"
        "#endif\n"
        "    },\n");
  }
  c_printer_->Print("};\n");
  c_printer_->Print("\n");
}

void LWPBCodeGenerator::PrintServiceMethods(
    const ServiceDescriptor& service_descriptor) const {
  // Print reference to method array
  string array_name = ServiceDescriptorMethodArray(service_descriptor);
  h_printer_->Print("extern const struct lwpb_method_desc $array$[];\n",
                    "array", array_name);
  h_printer_->Print("\n");
      
  // Print method id's
  string service_name = service_descriptor.name();
  h_printer_->Print("// '$name$' method descriptor pointers\n", "name", service_name);
    
  for (int i = 0; i < service_descriptor.method_count(); ++i) {
    const MethodDescriptor &method_descriptor = *service_descriptor.method(i);
    string id = MethodDescriptorId(method_descriptor);
    string ptr = MethodDescriptorPtr(method_descriptor);
    h_printer_->Print("#define $id$ $ptr$\n", "id", id, "ptr", ptr);
  }
  h_printer_->Print("\n");
    
  // Print method descriptor array
  c_printer_->Print("// '$name$' method descriptors\n", "name", service_name);
  c_printer_->Print("const struct lwpb_method_desc $name$[] = {\n", "name", array_name);
  for (int i = 0; i < service_descriptor.method_count(); ++i) {
    const MethodDescriptor &method_descriptor = *service_descriptor.method(i);
    map <string, string> m;
    m["service"] = ServiceDescriptorId(service_descriptor);
    m["input"] = MessageDescriptorId(*method_descriptor.input_type());
    m["output"] = MessageDescriptorId(*method_descriptor.output_type());
    m["name"] = method_descriptor.name();
    c_printer_->Print(m,
        "    {\n"
        "        .service = $service$,\n"
        "        .req_desc = $input$,\n"
        "        .res_desc = $output$,\n"
        "#if LWPB_METHOD_NAMES\n"
        "        .name = \"$name$\",\n"
        "#endif\n"
        "    },\n");
  }
  c_printer_->Print("};\n");
  c_printer_->Print("\n");
}

string LWPBCodeGenerator::OptionsValue(
    const string& class_name, const string& serialized_options) const {
  if (serialized_options.length() == 0 || GeneratingDescriptorProto()) {
    return "None";
  } else {
    string full_class_name = "descriptor_pb2." + class_name;
    return "descriptor._ParseOptions(" + full_class_name + "(), '"
        + CEscape(serialized_options)+ "')";
  }
}

bool LWPBCodeGenerator::GeneratingDescriptorProto() const {
  return file_->name() == "google/protobuf/descriptor.proto";
}

// Returns the unique Python module-level identifier given to a descriptor.
// This name is module-qualified iff the given descriptor describes an
// entity that doesn't come from the current file.
template <typename DescriptorT>
string LWPBCodeGenerator::ModuleLevelDescriptorName(
    const DescriptorT& descriptor) const {
  // FIXME(robinson):
  // We currently don't worry about collisions with underscores in the type
  // names, so these would collide in nasty ways if found in the same file:
  //   OuterProto.ProtoA.ProtoB
  //   OuterProto_ProtoA.ProtoB  # Underscore instead of period.
  // As would these:
  //   OuterProto.ProtoA_.ProtoB
  //   OuterProto.ProtoA._ProtoB  # Leading vs. trailing underscore.
  // (Contrived, but certainly possible).
  //
  // The C++ implementation doesn't guard against this either.  Leaving
  // it for now...
  string name = NamePrefixedWithNestedTypes(descriptor, "_");
  // We now have the name relative to its own module.  Also qualify with
  // the module name iff this descriptor is from a different .proto file.
  if (descriptor.file() != file_) {
    name = ModuleName(descriptor.file()->name()) + "_" + name;
  }
  UpperString(&name);
  return name;
}

// Returns the name of the message class itself, not the descriptor.
// Like ModuleLevelDescriptorName(), module-qualifies the name iff
// the given descriptor describes an entity that doesn't come from
// the current file.
string LWPBCodeGenerator::ModuleLevelMessageName(const Descriptor& descriptor) const {
  string name = NamePrefixedWithNestedTypes(descriptor, ".");
  if (descriptor.file() != file_) {
    name = ModuleName(descriptor.file()->name()) + "." + name;
  }
  return name;
}

// Returns the unique Python module-level identifier given to a service
// descriptor.
string LWPBCodeGenerator::ModuleLevelServiceDescriptorName(
    const ServiceDescriptor& descriptor) const {
  string name = descriptor.name();
  UpperString(&name);
  name = "_" + name;
  if (descriptor.file() != file_) {
    name = ModuleName(descriptor.file()->name()) + "." + name;
  }
  return name;
}

