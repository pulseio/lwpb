CXXFLAGS = -I../protobuf-2.5.0/src
LDFLAGS = -lprotoc -lprotobuf

all: protoc-gen-lwpb

protoc-gen-lwpb: lwpb_code_generator.o protoc_gen_lwpb.o
	$(CXX) -o $@ $(CFLAGS) $^ $(LDFLAGS)

clean:
	rm -r *.o
