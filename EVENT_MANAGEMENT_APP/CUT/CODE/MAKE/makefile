IDIR=../include
CC=gcc
BDIR=../bin
ODIR=../obj
SDIR=../src

OFILES= $(ODIR)/eve_main.o $(ODIR)/eve_menu.o $(ODIR)/eve_func1.o $(ODIR)/eve_func2.o

eveapp: $(OFILES)
	$(CC) -o $(BDIR)/eveapp $(OFILES)

$(ODIR)/eve_main.o: $(SDIR)/eve_main.c $(IDIR)/*
	$(CC) -o $(ODIR)/eve_main.o -c $(SDIR)/eve_main.c 

$(ODIR)/eve_menu.o: $(SDIR)/eve_menu.c $(IDIR)/*
	$(CC) -o $(ODIR)/eve_menu.o -c $(SDIR)/eve_menu.c

$(ODIR)/eve_func1.o: $(SDIR)/eve_func1.c $(IDIR)/*
	$(CC) -o $(ODIR)/eve_func1.o -c $(SDIR)/eve_func1.c

$(ODIR)/eve_func2.o: $(SDIR)/eve_func2.c $(IDIR)/*
	$(CC) -o $(ODIR)/eve_func2.o -c $(SDIR)/eve_func2.c
clean:
	rm $(ODIR)/*




