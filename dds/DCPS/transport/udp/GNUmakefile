# -*- makefile -*-
#----------------------------------------------------------------------------
#       GNU ACE Workspace
#
# $Id: GNUACEWorkspaceCreator.pm 2490 2015-03-20 20:50:04Z mitza $
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# /home/borotech/Development/ACE_wrappers/bin/mwc.pl -type gnuace DDS_TAOv2_all.mwc
#
#----------------------------------------------------------------------------

MAKEFILE = GNUmakefile

ifeq ($(findstring k,$(MAKEFLAGS)),k)
  KEEP_GOING = -
endif

include $(ACE_ROOT)/include/makeinclude/macros.GNU

all: OpenDDS_Udp

depend: OpenDDS_Udp-depend

REMAINING_TARGETS := $(filter-out all depend,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.OpenDDS_Udp $(@)

.PHONY: OpenDDS_Udp
OpenDDS_Udp:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.OpenDDS_Udp all

.PHONY: OpenDDS_Udp-depend
OpenDDS_Udp-depend:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.OpenDDS_Udp depend

project_name_list:
	@echo OpenDDS_Udp
