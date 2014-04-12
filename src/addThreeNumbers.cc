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


using v8::FunctionTemplate;
using v8::Handle;
using v8::HandleScope;
using v8::HeapSnapshot;
using v8::Isolate;
using v8::Object;
using v8::OutputStream;
using v8::String;
using v8::V8;
using v8::Value;

// This function returns the sum of the three elements, x, y, and z.
Handle<v8::Value> AddThreeNumbers(const Arguments& args) {
  v8::Isolate* isolate = v8::Isolate::GetCurrent();

  HandleScope handle_scope;
  
  // We will be creating temporary handles so we use a handle scope.
  //HandleScope handle_scope(isolate);

  Local<Number> sum = Number::New(args[0]->NumberValue() + args[1]-> NumberValue() + args[2]->NumberValue());

  // Return the value through Close.
  return handle_scope.Close(sum);
}

int main(int argc, char *argv[])
{
  return 0;
}

void init(Handle<Object> target){
        target-> Set(String::NewSymbol("addThreeNumbers"),
                FunctionTemplate::New(AddThreeNumbers)->GetFunction());
}


NODE_MODULE(customSnapShot, init);
