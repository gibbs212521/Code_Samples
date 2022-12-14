### app file ending ###
# $(MAKE_CALL) code here 
!ifndef 0 # \
EXE_FILETYPE=.exe # \
FD=\ #
!else
# Make code here 
EXE_FILETYPE=# 
FD=/#
#
!endif



##### CONSTANT BOILER PLATE #######
DIRPATH=.$(FD)src
BINPATH=.$(FD)bin
OBJPATH=.$(FD)obj
TESTPATH=.$(FD)test
TEST_BINPATH=$(TESTPATH)$(FD)bin
TEST_OBJPATH=$(TESTPATH)$(FD)obj

FILENAME=euler_project
TESTNAME=test_$(FILENAME)


INCL= 
CC=gcc
CFLAGS= #-I $(INCL)


TESTBIN=$(TEST_OBJPATH)$(FD)$(TESTNAME).o
CTEST=$(TESTPATH)$(FD)$(TESTNAME).c
TEST_EXE=$(TEST_BINPATH)$(FD)$(TESTNAME)$(EXE_FILETYPE)

SOURCES = $(CTEST)
APPS = $(TEST_EXE)

FILEBIN=$(OBJPATH)$(FD)$(FILENAME).o
CFILE=$(DIRPATH)$(FD)$(FILENAME).c
FILE_EXE=$(BINPATH)$(FD)$(FILENAME)$(EXE_FILETYPE)

SOURCES = $(SOURCES) $(CFILE)
APPS = $(APPS) $(FILE_EXE)
OBJBUILDS = 0
TEST_OBJBUILDS = 0


##### VARYING FILE BOILER PLATE #######
PROJECT_PATH=$(DIRPATH)$(FD)project
BASENAME=project


OBJ1NAME=$(BASENAME)_1
OBJ1SRC=$(PROJECT_PATH)$(FD)$(OBJ1NAME).c
OBJ1=$(OBJPATH)$(FD)$(OBJ1NAME).o

SOURCES = $(SOURCES) $(OBJ1SRC)
OBJECTS = $(OBJ1)
OBJBUILDS = 1



##### VARYING FILE BOILER PLATE #######
TEST_OBJ1NAME=test
TEST_OBJ1SRC=$(TESTPATH)$(FD)$(TEST_OBJ1NAME).c
TEST_OBJ1=$(TEST_OBJPATH)$(FD)$(TEST_OBJ1NAME).o

SOURCES = $(SOURCES) $(TEST_OBJ1SRC)
TEST_OBJECTS = $(TEST_OBJ1)
TEST_OBJBUILDS = 1


TEST_PROJECT_PATH=$(TESTPATH)

TEST_OBJ2NAME=test_$(TEST_OBJ1)
TEST_OBJ2SRC=$(TESTPATH)$(FD)$(TEST_OBJ2NAME).c
TEST_OBJ2=$(TEST_OBJPATH)$(FD)$(TEST_OBJ2NAME).o

SOURCES = $(SOURCES) 
TEST_OBJECTS = $(TEST_OBJECTS)



# Code below should allow $(MAKE_CALL) and make to operate successfully
# $(MAKE_CALL) code here $(FD)
!ifndef 0# $(FD)
MV = move # $(FD)
RM=del # $(FD)
RMDIR=rmdir # $(FD)
CP=copy # $(FD)
MAKE_CALL=nmake # $(FD)
IF_FILE=IF EXIST # $(FD)
THEN_DO= # $(FD)
IF_NOT_FILE=IF NOT EXIST # $(FD)
IF_NOT_THEN_DO= # $(FD)
INSERT_FILE= call > # $(FD)
EMPTY_TXT=empty.txt # $(FD)
!else
ifeq (0,0) #
# Make code here 
MV=mv -f # 
RM=rm -f #
RMDIR=rm -rf #
CP=cp -f # 
MAKE_CALL=make #
IF_FILE=test -f #
THEN_DO= && #
IF_NOT_FILE=test -f #
IF_NOT_THEN_DO= || #
INSERT_FILE= ># 
EMPTY_TXT=.empty.txt #
endif #
# $(FD)
!endif






##### CONSTANT BUILD #######
MAKE: $(FILEBIN) $(TESTBIN) $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(FILEBIN) $(OBJECTS) -o $(FILE_EXE)
	$(CC) $(CFLAGS) $(TESTBIN) $(OBJECTS) $(TEST_OBJECTS) -o $(TEST_EXE)
	$(MAKE_CALL) clean_up

MAKE_OBJ: $(FILEBIN) $(TESTBIN) $(OBJECTS)
	$(CC) $(CFLAGS) $(FILEBIN) $(OBJECTS) -o $(FILE_EXE)
	$(CC) $(CFLAGS) $(TESTBIN) $(OBJECTS) $(TEST_OBJECTS) -o $(TEST_EXE)

$(FILEBIN): $(CFILE)
	$(MAKE_CALL) BUILD_DIR
	$(MAKE_CALL) build
	$(MAKE_CALL) BUILD_OBJ
	$(CC) -c $(CFLAGS) $(CFILE) -o $(FILEBIN)

$(TESTBIN): $(CTEST)
	$(MAKE_CALL) BUILD_TEST_DIR
	$(MAKE_CALL) build
	$(MAKE_CALL) BUILD_OBJ
	$(CC) -c $(CFLAGS) $(CTEST) -o $(TESTBIN)


MAKE_TEST: $(TESTBIN) $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(TESTBIN) $(OBJECTS) $(TEST_OBJECTS) -o $(TEST_EXE)
	$(MAKE_CALL) clean_tests

MAKE_CORE: $(FILEBIN) $(OBJECTS)
	$(CC) $(CFLAGS) $(FILEBIN) $(OBJECTS) -o $(FILE_EXE)
	$(MAKE_CALL) clean_core

build::
	$(CP) blankmake Makefile
# $(MAKE_CALL) code here \
	IF $(OBJBUILDS) GTR 0 \
	FOR %%i IN ($(OBJBUILDS))\
		DO \
		@echo( $$(CC) $$(CFLAGS) -c $$(OBJ%%iSRC) -o $$(OBJ%%i)  >> Makefile
#	nmake only \
	IF $(TEST_OBJBUILDS) GTR 0 \
	FOR %%i IN ($(TST_OBJBUILDS))\
		DO \
		@echo( $$(CC) $$(CFLAGS) -c $$(TST_OBJ%%iSRC) -o $$(TST_OBJ%%i)  >> Makefile
#	nmake only effective multiline commenting out # \
	@echo <<
	for num in $(OBJBUILDS); do \
		echo "	"$$"(CC)" $$"(CFLAGS)" -c $$"(OBJ"$${num}"SRC)" -o $$"(OBJ"$${num}")" >> Makefile;\
		done #
	for num in $(TST_OBJBUILDS); do \
		echo "	"$$"(CC)" $$"(CFLAGS)" -c $$"(TST_OBJ"$${num}"SRC)" -o $$"(TST_OBJ"$${num}")" >> Makefile;\
		done #
#		$(foeach var,$(OBJBUILDS),@echo	$$(CC) $$(CFLAGS) -c $$(OBJ%%iSRC) -o $$(OBJ%%i) >> Makefile;) #
#	nmake only # \
<<NOKEEP

fast:
	$(MAKE_CALL) clean_core
	$(MAKE_CALL) MAKE_CORE
	$(MAKE_CALL) run

retest:
	$(MAKE_CALL) clean_tests

run:
	$(FILE_EXE)

test:
	$(TEST_EXE)


clean:
	$(RM) $(APPS)
	$(RM) $(BINPATH)$(FD)$(EMPTY_TXT)
	$(RMDIR) $(BINPATH)

clean_up:
	$(MAKE_CALL) clean_core
	$(MAKE_CALL) clean_tests
	$(RM) $(OBJPATH)$(FD)$(EMPTY_TXT)
	$(RMDIR) $(OBJPATH)
	
clean_core:
	$(IF_FILE) $(FILEBIN) $(THEN_DO) $(RM) $(FILEBIN)
	$(IF_FILE) $(OBJ1) $(THEN_DO) $(RM) $(OBJECTS)
	$(IF_FILE) $(OBJPATH)$(FD)$(EMPTY_TXT) $(THEN_DO) $(RM) $(OBJPATH)$(FD)$(EMPTY_TXT)
	$(RMDIR) $(OBJPATH)

clean_tests:
	$(IF_FILE) $(TESTBIN) $(THEN_DO) $(RM) $(TESTBIN)
	$(IF_FILE) $(TEST_OBJ1) $(THEN_DO) $(RM) $(TEST_OBJECTS)
	$(IF_FILE) $(TEST_OBJPATH)$(FD)$(EMPTY_TXT) $(THEN_DO) $(RM) $(TEST_OBJPATH)$(FD)$(EMPTY_TXT)
	$(RMDIR) $(TEST_OBJPATH)

clean_all:
	$(MAKE_CALL) clean_up
	$(MAKE_CALL) clean

BUILD_DIR:
	$(IF_NOT_FILE) $(BINPATH)$(FD)$(EMPTY_TXT) $(IF_NOT_THEN_DO) mkdir $(BINPATH)
	$(IF_NOT_FILE) $(BINPATH)$(FD)$(EMPTY_TXT) $(IF_NOT_THEN_DO) $(INSERT_FILE) $(BINPATH)$(FD)$(EMPTY_TXT)
	$(IF_NOT_FILE) $(OBJPATH)$(FD)$(EMPTY_TXT) $(IF_NOT_THEN_DO) mkdir $(OBJPATH)
	$(IF_NOT_FILE) $(OBJPATH)$(FD)$(EMPTY_TXT) $(IF_NOT_THEN_DO) $(INSERT_FILE) $(OBJPATH)$(FD)$(EMPTY_TXT)

BUILD_TEST_DIR:
	$(IF_NOT_FILE) $(TEST_BINPATH)$(FD)$(EMPTY_TXT) $(IF_NOT_THEN_DO) mkdir $(TEST_BINPATH)
	$(IF_NOT_FILE) $(TEST_BINPATH)$(FD)$(EMPTY_TXT) $(IF_NOT_THEN_DO) $(INSERT_FILE) $(TEST_BINPATH)$(FD)$(EMPTY_TXT)
	$(IF_NOT_FILE) $(TEST_OBJPATH)$(FD)$(EMPTY_TXT) $(IF_NOT_THEN_DO) mkdir $(TEST_OBJPATH)
	$(IF_NOT_FILE) $(TEST_OBJPATH)$(FD)$(EMPTY_TXT) $(IF_NOT_THEN_DO) $(INSERT_FILE) $(TEST_OBJPATH)$(FD)$(EMPTY_TXT)
	
BUILD_OBJ:
	@echo building...
#####	VARIABLE BUILD	#####
