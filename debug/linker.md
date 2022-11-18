# objcopy  localize symbol of library
ld -r obj1.o obj2.o ... objn.o -o static1.o
objcopy --localize-hidden static1.o static2.o
ar -rcs mylib.a static2.o


$(LIB_AR_ALL): $(LIB_AR_UNSCOPED) $(LIB_LINK) $(MAKEFILE_DEPS)                  
        $(OBJCOPY) --localize-hidden `sed -n 's/^       *\([a-zA-Z0-9_]*\);$$/-G \1/p' $(LIB_LINK)` $< $@

