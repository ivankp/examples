EXE = no_rpath with_rpath with_runpath

DIR = lib1 lib2

all: $(EXE) lib2/libprt.so

$(DIR):
	mkdir -p $@

prt%.o: prt%.c prt.h
	gcc -fPIC -g -c -Wall $<

lib%/libprt.so: prt%.o lib%
	gcc -shared -Wl,-soname,libprt.so -o $@ $< -lc

no_rpath: main.c lib1/libprt.so
	gcc -Llib1 $< -o $@ -lprt

with_rpath: main.c lib1/libprt.so
	gcc -Wl,-rpath=lib1 -Llib1 $< -o $@ -lprt

with_runpath: main.c lib1/libprt.so
	gcc -Wl,-rpath=lib1,--enable-new-dtags -Llib1 $< -o $@ -lprt

$(EXE): prt.h

clean:
	rm -rf $(DIR) $(EXE)
