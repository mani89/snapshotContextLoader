cmd_Release/takeCustomSnap.node := ./gyp-mac-tool flock ./Release/linker.lock c++ -bundle -Wl,-search_paths_first -mmacosx-version-min=10.5 -arch x86_64 -L./Release  -o Release/takeCustomSnap.node Release/obj.target/takeCustomSnap/src/takeCustomSnap.o -undefined dynamic_lookup
