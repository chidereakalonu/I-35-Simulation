# Modular Make - top level makefile
PROJPATH = $(PWD)
PROJNAME = $(notdir $(PROJPATH))

include $(wildcard mk/*.mk)
# TARGET := $(PROJNAME)$(EXT)
TSTTGT := testapp$(EXT)
