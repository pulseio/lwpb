#include <google/protobuf/compiler/code_generator.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/printer.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/stubs/strutil.h>
#include <google/protobuf/stubs/substitute.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>

using namespace google::protobuf;

class LWPBCodeGenerator : public compiler::CodeGenerator {
    
 public:
  bool Generate(const FileDescriptor * file,
                const string & parameter,
                compiler::GeneratorContext * generator_context,
                string * error) const;
  
  LWPBCodeGenerator();
  ~LWPBCodeGenerator();

 private:

  string FileDescriptorIncludeGuard(const FileDescriptor& descriptor) const;
  string FileDescriptorMessageArray(const FileDescriptor& descriptor) const;
  string FileDescriptorServiceArray(const FileDescriptor& descriptor) const;
  string MessageDescriptorId(const Descriptor& descriptor) const;
  string MessageDescriptorPtr(const Descriptor& descriptor) const;
  string MessageDescriptorFieldArray(const Descriptor& descriptor) const;
  string FieldDescriptorId(const FieldDescriptor& descriptor) const;
  string FieldDescriptorPtr(const FieldDescriptor& descriptor) const;
  string FieldDescriptorOptLabel(const FieldDescriptor& field) const;
  string FieldDescriptorOptTyp(const FieldDescriptor& field) const;
  string FieldDescriptorOptFlags(const FieldDescriptor& field) const;
  string ServiceDescriptorId(const ServiceDescriptor& descriptor) const;
  string ServiceDescriptorPtr(const ServiceDescriptor& descriptor) const;
  string ServiceDescriptorMethodArray(const ServiceDescriptor& descriptor) const;
  string MethodDescriptorId(const MethodDescriptor& descriptor) const;
  string MethodDescriptorPtr(const MethodDescriptor& descriptor) const;
     
  void CreateEnumList() const;
  void AddNestedEnums(const Descriptor& containing_descriptor) const;

  void CreateMessageList() const;
  void AddNestedMessages(const Descriptor& containing_descriptor) const;
  int GetMessageIndex(const Descriptor* message_descriptor) const;
  
  void PrintHeader() const;
  void PrintFooter() const;
  
  void PrintImports() const;
  void PrintEnumDescriptors() const;
  void PrintEnumDescriptor(const EnumDescriptor& enum_descriptor) const;
  void PrintMessageDescriptors() const;
  void PrintDescriptorFields(const Descriptor& message_descriptor) const;
  void PrintServiceDescriptors() const;
  void PrintServiceMethods(const ServiceDescriptor& service_descriptor) const;

  string OptionsValue(const string& class_name,
                      const string& serialized_options) const;
  bool GeneratingDescriptorProto() const;

  template <typename DescriptorT>
  string ModuleLevelDescriptorName(const DescriptorT& descriptor) const;
  string ModuleLevelMessageName(const Descriptor& descriptor) const;
  string ModuleLevelServiceDescriptorName(
      const ServiceDescriptor& descriptor) const;

  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(LWPBCodeGenerator);

  mutable const FileDescriptor* file_;  // Set in Generate().  Under mutex_.
  mutable io::Printer* h_printer_;  // Set in Generate().  Under mutex_.
  mutable io::Printer* c_printer_;  // Set in Generate().  Under mutex_.

  mutable vector<const EnumDescriptor*> enums_;
  mutable vector<const Descriptor*> messages_;

};
