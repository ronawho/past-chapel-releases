#
# Copyright (c) 2004-2013, Cray Inc.  (See LICENSE file for more details)
#

#
# top-level Chapel Makefile
#

export CHPL_MAKE_HOME=$(shell pwd)
include ./make/Makefile.base

default: all

all: comprt
	@test -r Makefile.devel && $(MAKE) develall || echo ""

comprt: FORCE
	@$(MAKE) compiler
	@$(MAKE) runtime
	@$(MAKE) modules

compiler: FORCE
	cd compiler && $(MAKE)

modules: FORCE
	cd modules && $(MAKE)

runtime: FORCE
	cd runtime && $(MAKE)

third-party: FORCE
	cd third-party && $(MAKE)

clean: FORCE
	cd compiler && $(MAKE) clean
	cd runtime && $(MAKE) clean
	cd modules && $(MAKE) clean

cleandeps: FORCE
	cd compiler && $(MAKE) cleandeps
	cd runtime && $(MAKE) cleandeps

clobber: FORCE
	cd compiler && $(MAKE) clobber
	cd runtime && $(MAKE) clobber
	cd modules && $(MAKE) clobber
	cd third-party && $(MAKE) clobber
	rm -rf bin
	rm -rf lib

depend:
	@echo "make depend has been deprecated for the time being"

-include Makefile.devel

FORCE:
