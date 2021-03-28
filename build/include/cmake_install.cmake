# Install script for directory: /workspaces/odas/odas/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/workspaces/odas/odas/include/odas/aconnector/acon_categories.h"
    "/workspaces/odas/odas/include/odas/aconnector/acon_hops.h"
    "/workspaces/odas/odas/include/odas/aconnector/acon_pots.h"
    "/workspaces/odas/odas/include/odas/aconnector/acon_powers.h"
    "/workspaces/odas/odas/include/odas/aconnector/acon_spectra.h"
    "/workspaces/odas/odas/include/odas/aconnector/acon_targets.h"
    "/workspaces/odas/odas/include/odas/aconnector/acon_tracks.h"
    "/workspaces/odas/odas/include/odas/ainjector/ainj_targets.h"
    "/workspaces/odas/odas/include/odas/amessage/amsg_categories.h"
    "/workspaces/odas/odas/include/odas/amessage/amsg_hops.h"
    "/workspaces/odas/odas/include/odas/amessage/amsg_pots.h"
    "/workspaces/odas/odas/include/odas/amessage/amsg_powers.h"
    "/workspaces/odas/odas/include/odas/amessage/amsg_spectra.h"
    "/workspaces/odas/odas/include/odas/amessage/amsg_targets.h"
    "/workspaces/odas/odas/include/odas/amessage/amsg_tracks.h"
    "/workspaces/odas/odas/include/odas/amodule/amod_classify.h"
    "/workspaces/odas/odas/include/odas/amodule/amod_istft.h"
    "/workspaces/odas/odas/include/odas/amodule/amod_mapping.h"
    "/workspaces/odas/odas/include/odas/amodule/amod_noise.h"
    "/workspaces/odas/odas/include/odas/amodule/amod_resample.h"
    "/workspaces/odas/odas/include/odas/amodule/amod_ssl.h"
    "/workspaces/odas/odas/include/odas/amodule/amod_sss.h"
    "/workspaces/odas/odas/include/odas/amodule/amod_sst.h"
    "/workspaces/odas/odas/include/odas/amodule/amod_stft.h"
    "/workspaces/odas/odas/include/odas/amodule/amod_volume.h"
    "/workspaces/odas/odas/include/odas/asink/asnk_categories.h"
    "/workspaces/odas/odas/include/odas/asink/asnk_hops.h"
    "/workspaces/odas/odas/include/odas/asink/asnk_pots.h"
    "/workspaces/odas/odas/include/odas/asink/asnk_powers.h"
    "/workspaces/odas/odas/include/odas/asink/asnk_spectra.h"
    "/workspaces/odas/odas/include/odas/asink/asnk_tracks.h"
    "/workspaces/odas/odas/include/odas/asource/asrc_hops.h"
    "/workspaces/odas/odas/include/odas/connector/con_categories.h"
    "/workspaces/odas/odas/include/odas/connector/con_hops.h"
    "/workspaces/odas/odas/include/odas/connector/con_pots.h"
    "/workspaces/odas/odas/include/odas/connector/con_powers.h"
    "/workspaces/odas/odas/include/odas/connector/con_spectra.h"
    "/workspaces/odas/odas/include/odas/connector/con_targets.h"
    "/workspaces/odas/odas/include/odas/connector/con_tracks.h"
    "/workspaces/odas/odas/include/odas/general/format.h"
    "/workspaces/odas/odas/include/odas/general/interface.h"
    "/workspaces/odas/odas/include/odas/general/link.h"
    "/workspaces/odas/odas/include/odas/general/mic.h"
    "/workspaces/odas/odas/include/odas/general/samplerate.h"
    "/workspaces/odas/odas/include/odas/general/soundspeed.h"
    "/workspaces/odas/odas/include/odas/general/spatialfilter.h"
    "/workspaces/odas/odas/include/odas/general/thread.h"
    "/workspaces/odas/odas/include/odas/init/combining.h"
    "/workspaces/odas/odas/include/odas/init/delay.h"
    "/workspaces/odas/odas/include/odas/init/directivity.h"
    "/workspaces/odas/odas/include/odas/init/hit.h"
    "/workspaces/odas/odas/include/odas/init/linking.h"
    "/workspaces/odas/odas/include/odas/init/scanning.h"
    "/workspaces/odas/odas/include/odas/init/space.h"
    "/workspaces/odas/odas/include/odas/init/windowing.h"
    "/workspaces/odas/odas/include/odas/injector/inj_targets.h"
    "/workspaces/odas/odas/include/odas/message/msg_categories.h"
    "/workspaces/odas/odas/include/odas/message/msg_hops.h"
    "/workspaces/odas/odas/include/odas/message/msg_pots.h"
    "/workspaces/odas/odas/include/odas/message/msg_powers.h"
    "/workspaces/odas/odas/include/odas/message/msg_spectra.h"
    "/workspaces/odas/odas/include/odas/message/msg_targets.h"
    "/workspaces/odas/odas/include/odas/message/msg_tracks.h"
    "/workspaces/odas/odas/include/odas/module/mod_classify.h"
    "/workspaces/odas/odas/include/odas/module/mod_istft.h"
    "/workspaces/odas/odas/include/odas/module/mod_mapping.h"
    "/workspaces/odas/odas/include/odas/module/mod_noise.h"
    "/workspaces/odas/odas/include/odas/module/mod_resample.h"
    "/workspaces/odas/odas/include/odas/module/mod_ssl.h"
    "/workspaces/odas/odas/include/odas/module/mod_sss.h"
    "/workspaces/odas/odas/include/odas/module/mod_sst.h"
    "/workspaces/odas/odas/include/odas/module/mod_stft.h"
    "/workspaces/odas/odas/include/odas/module/mod_volume.h"
    "/workspaces/odas/odas/include/odas/odas.h"
    "/workspaces/odas/odas/include/odas/signal/acorr.h"
    "/workspaces/odas/odas/include/odas/signal/aimg.h"
    "/workspaces/odas/odas/include/odas/signal/area.h"
    "/workspaces/odas/odas/include/odas/signal/assignation.h"
    "/workspaces/odas/odas/include/odas/signal/beampattern.h"
    "/workspaces/odas/odas/include/odas/signal/category.h"
    "/workspaces/odas/odas/include/odas/signal/coherence.h"
    "/workspaces/odas/odas/include/odas/signal/delta.h"
    "/workspaces/odas/odas/include/odas/signal/demixing.h"
    "/workspaces/odas/odas/include/odas/signal/env.h"
    "/workspaces/odas/odas/include/odas/signal/frame.h"
    "/workspaces/odas/odas/include/odas/signal/freq.h"
    "/workspaces/odas/odas/include/odas/signal/gain.h"
    "/workspaces/odas/odas/include/odas/signal/hop.h"
    "/workspaces/odas/odas/include/odas/signal/impulse.h"
    "/workspaces/odas/odas/include/odas/signal/index.h"
    "/workspaces/odas/odas/include/odas/signal/kalman.h"
    "/workspaces/odas/odas/include/odas/signal/map.h"
    "/workspaces/odas/odas/include/odas/signal/mask.h"
    "/workspaces/odas/odas/include/odas/signal/mixture.h"
    "/workspaces/odas/odas/include/odas/signal/pair.h"
    "/workspaces/odas/odas/include/odas/signal/particle.h"
    "/workspaces/odas/odas/include/odas/signal/pitch.h"
    "/workspaces/odas/odas/include/odas/signal/point.h"
    "/workspaces/odas/odas/include/odas/signal/postprob.h"
    "/workspaces/odas/odas/include/odas/signal/pot.h"
    "/workspaces/odas/odas/include/odas/signal/scan.h"
    "/workspaces/odas/odas/include/odas/signal/spatialgain.h"
    "/workspaces/odas/odas/include/odas/signal/spatialindex.h"
    "/workspaces/odas/odas/include/odas/signal/spatialmask.h"
    "/workspaces/odas/odas/include/odas/signal/steer.h"
    "/workspaces/odas/odas/include/odas/signal/target.h"
    "/workspaces/odas/odas/include/odas/signal/tau.h"
    "/workspaces/odas/odas/include/odas/signal/tdoa.h"
    "/workspaces/odas/odas/include/odas/signal/track.h"
    "/workspaces/odas/odas/include/odas/signal/triangle.h"
    "/workspaces/odas/odas/include/odas/signal/window.h"
    "/workspaces/odas/odas/include/odas/signal/xcorr.h"
    "/workspaces/odas/odas/include/odas/sink/snk_categories.h"
    "/workspaces/odas/odas/include/odas/sink/snk_hops.h"
    "/workspaces/odas/odas/include/odas/sink/snk_pots.h"
    "/workspaces/odas/odas/include/odas/sink/snk_powers.h"
    "/workspaces/odas/odas/include/odas/sink/snk_spectra.h"
    "/workspaces/odas/odas/include/odas/sink/snk_tracks.h"
    "/workspaces/odas/odas/include/odas/source/src_hops.h"
    "/workspaces/odas/odas/include/odas/system/acorr2pitch.h"
    "/workspaces/odas/odas/include/odas/system/demixing2env.h"
    "/workspaces/odas/odas/include/odas/system/demixing2freq.h"
    "/workspaces/odas/odas/include/odas/system/env2env.h"
    "/workspaces/odas/odas/include/odas/system/frame2freq.h"
    "/workspaces/odas/odas/include/odas/system/frame2hop.h"
    "/workspaces/odas/odas/include/odas/system/freq2acorr.h"
    "/workspaces/odas/odas/include/odas/system/freq2env.h"
    "/workspaces/odas/odas/include/odas/system/freq2frame.h"
    "/workspaces/odas/odas/include/odas/system/freq2freq.h"
    "/workspaces/odas/odas/include/odas/system/freq2xcorr.h"
    "/workspaces/odas/odas/include/odas/system/gain2mask.h"
    "/workspaces/odas/odas/include/odas/system/hop2frame.h"
    "/workspaces/odas/odas/include/odas/system/hop2hop.h"
    "/workspaces/odas/odas/include/odas/system/kalman2coherence.h"
    "/workspaces/odas/odas/include/odas/system/kalman2kalman.h"
    "/workspaces/odas/odas/include/odas/system/mixture2mixture.h"
    "/workspaces/odas/odas/include/odas/system/particle2coherence.h"
    "/workspaces/odas/odas/include/odas/system/particle2particle.h"
    "/workspaces/odas/odas/include/odas/system/pitch2category.h"
    "/workspaces/odas/odas/include/odas/system/steer2demixing.h"
    "/workspaces/odas/odas/include/odas/system/track2gain.h"
    "/workspaces/odas/odas/include/odas/system/track2steer.h"
    "/workspaces/odas/odas/include/odas/system/xcorr2aimg.h"
    "/workspaces/odas/odas/include/odas/system/xcorr2xcorr.h"
    "/workspaces/odas/odas/include/odas/utils/cmatrix.h"
    "/workspaces/odas/odas/include/odas/utils/fft.h"
    "/workspaces/odas/odas/include/odas/utils/fifo.h"
    "/workspaces/odas/odas/include/odas/utils/gaussian.h"
    "/workspaces/odas/odas/include/odas/utils/gaussjordan.h"
    "/workspaces/odas/odas/include/odas/utils/inverse.h"
    "/workspaces/odas/odas/include/odas/utils/matrix.h"
    "/workspaces/odas/odas/include/odas/utils/pcm.h"
    "/workspaces/odas/odas/include/odas/utils/random.h"
    "/workspaces/odas/odas/include/odas/utils/transcendental.h"
    )
endif()

