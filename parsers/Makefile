all:
.SUFFIXES:
.SUFFIXES: .c .o
CFLAGS = GOBJECT_INTROSPECTION_CFLAGS = -I/usr/include/gobject-introspection-1.0 -I/usr/lib/libffi-3.2.1/include -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -pthread 
LIBS = GOBJECT_INTROSPECTION_LIBS = -lgirepository-1.0 -lgobject-2.0 -lglib-2.0 

.c.o:
	$(MAKE) -C .. parsers/$@
%:
	$(MAKE) -C .. $@
