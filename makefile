SOURCES = pmt.c \
          dtk_window.c \
          dtk_menu_bar.c \
          dtk_frame.c
OBJS    = ${SOURCES:.c=.o}
CFLAGS  = `pkg-config gtk+-3.0 libgda-4.0 --cflags`
LDADD   = `pkg-config gtk+-3.0 libgda-4.0 --libs`
CC      = gcc
DEBUG   = -g
PACKAGE = pmt

all: ${OBJS}
	${CC} ${DEBUG} -o ${PACKAGE} ${OBJS} ${LDADD}

.c.o:
	${CC} ${DEBUG} ${CFLAGS} -c $<

clean:
	rm -f *~ *.o ${PACKAGE}
