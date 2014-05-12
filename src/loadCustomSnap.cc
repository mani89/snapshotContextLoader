/* 
Author : Manikandan Soundarapandian
*/

#include "node.h"
#include "node_version.h"
#include "uv.h"
#include "v8.h"
#include "v8-profiler.h"
#include "v8-testing.h"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/api.h"
#include "../src/serialize.h"
#include "../src/snapshot.h"
#include "../src/platform.h"
#include "../src/bootstrapper.h"
#include "../src/natives.h"
#include "../src/globals.h"




//Load a custom snapshot
Handle<Value> loadCustomSnap(const Arguments& args) {

  
  
  if (i::Snapshot::Initialize("newSnap.cc"))
  {
  	 v8::internal::Handle<v8::internal::Context> new_context = i::Snapshot::NewContextFromSnapshot();
	printf("Success");
  } 
  
//  return new_context;
}


static void init(Handle<Object> target){
        target-> Set(String::NewSymbol("loadCustomSnap"),
                FunctionTemplate::New(loadCustomSnap)->GetFunction());
}


NODE_MODULE(loadCustomSnap, init);
