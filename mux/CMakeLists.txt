#*******************************************************************************
# Copyright (C) Sierra Wireless Inc. Use of this work is subject to license.
#
# Contributors:
#     Sierra Wireless - initial API and implementation
#*******************************************************************************

# TODO: Convert this into a "command-line app" when that feature is available.

mkexe(  mux
            ../muxctrl
            -i ${LEGATO_ROOT}/interfaces
            -v
        DEPENDS
            legato
            Component.cdef
            muxCtrl.c
            ${LEGATO_ROOT}/interfaces/mangoh_muxCtrl.api
     )
