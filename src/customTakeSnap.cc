/* 
Author : Manikandan Soundarapandian
*/

#include "node.h"
#include "node_version.h"
#include "uv.h"
#include "v8.h"
#include "v8-profiler.h"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>

using namespace v8;

class MyOutputStream :public OutputStream
{
  public:
    MyOutputStream(FILE *stream): stream_(stream)
    { 
    }
    
    virtual void EndOfStream() {}
    
    virtual int GetChunkSize() { return 65536; }
    
    virtual WriteResult WriteAsciiChunk(char* data, int size)
    {
      const size_t len = static_cast<size_t>(size);
      size_t off = 0;

      while (off < len && !feof(stream_) && !ferror(stream_))
        off += fwrite(data + off, 1, len - off, stream_);

      return off == len ? kContinue : kAbort;
    }

  private:
    FILE* stream_;    
};


//Take a custom snapshot of the current context
Handle<v8::Value> customSnapShot(const Arguments& args) {

  HandleScope handle_scope;

  printf("Before File open");

  char scratch[256];
  uint64_t now = uv_hrtime();
  unsigned long sec = static_cast<unsigned long>(now / 1000000);
  unsigned long usec = static_cast<unsigned long>(now % 1000000);
  snprintf(scratch,
             sizeof(scratch),
             "mySnap.heapsnapshot",
             sec,
             usec);
  const char* filename = scratch;

  FILE *fp = fopen(filename, "w");
  //if(fp == NULL)
    //return 0;

  printf("File opened");

  const HeapSnapshot *mySnapShot = v8::HeapProfiler::TakeSnapshot(String::Empty());
      //isolate->GetHeapProfiler()->TakeHeapSnapshot(String::Empty()));
  MyOutputStream stream(fp);
  mySnapShot->Serialize(&stream, HeapSnapshot::kJSON);
  fclose(fp);

  // Return the value through Close.
  //return handle_scope.Close();
}


void init(Handle<Object> target){
  	v8::Isolate* isolate = v8::Isolate::GetCurrent();
        target-> Set(String::NewSymbol("customSnapShot"),
                FunctionTemplate::New(customSnapShot)->GetFunction());
}


NODE_MODULE(customSnapShot, init);
