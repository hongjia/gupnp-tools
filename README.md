GUPnP Tools
===========

GUPnP is an object-oriented open source framework for creating UPnP devices and
control points, written in C using GObject and libsoup. The GUPnP API is
intended to be easy to use, efficient and flexible.

GUPnP Tools are free replacements of Intel UPnP tools that use GUPnP. They
provides the following client and server side tools which enable one to easily
test and debug one's UPnP devices and control points:

  * Universal Control Point: a tool that enables one to discover UPnP devices
    and services, retrieve information about them, subscribe to events and
    invoke actions.

  * Network Light: a virtual light bulb that allows control points to switch
    it on and off, change its dimming level and query its current status. It
    also provides a simple UI to control all the network lights available on
    the network.

  * AV Control Point: a simple media player UI that enables one to discover and
    play multimedia contents available on a network. It is strictly a control
    point and therefore does not have any playback capabilities of it's own and
    relies on external UPnP MediaRenderer devices for actual playback.

  * Upload: a simple commandline utility that uploads files to known
    MediaServers. Use Universal Control Point for discovering the MediaServers.

Modifications
===========
  * gupnp-av-cp:
    - Showing current Track URI of selected renderer
    - Set renderer media address directly from URI input
