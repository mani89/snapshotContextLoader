cmd_Release/loadCustomSnap.node := ./gyp-mac-tool flock ./Release/linker.lock c++ -bundle -Wl,-search_paths_first -mmacosx-version-min=10.5 -arch x86_64 -L./Release  -o Release/loadCustomSnap.node Release/obj.target/loadCustomSnap/src/loadCustomSnap.o -undefined dynamic_lookup
