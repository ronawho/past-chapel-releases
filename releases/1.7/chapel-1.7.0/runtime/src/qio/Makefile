#
# Copyright (c) 2004-2013, Cray Inc.  (See LICENSE file for more details)
#

RUNTIME_ROOT = ../..
RUNTIME_SUBDIR = src/qio

ifndef CHPL_MAKE_HOME
export CHPL_MAKE_HOME=$(shell pwd)/$(RUNTIME_ROOT)/..
endif

#
# standard header
#
include $(RUNTIME_ROOT)/make/Makefile.runtime.head

QIO_OBJDIR = $(RUNTIME_OBJDIR)
include Makefile.share

SUBDIRS = regexp/$(CHPL_MAKE_REGEXP)
TARGETS = $(QIO_OBJS)

include $(RUNTIME_ROOT)/make/Makefile.runtime.subdirrules


FORCE:

#
# standard footer
#
include $(RUNTIME_ROOT)/make/Makefile.runtime.foot
