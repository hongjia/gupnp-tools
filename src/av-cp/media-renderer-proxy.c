/*
 * Copyright (C) 2007 Zeeshan Ali <zeenix@gstreamer.net>
 *
 * Authors: Zeeshan Ali <zeenix@gstreamer.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <string.h>

#include <libgupnp/gupnp-service-proxy.h>

#include "media-renderer-proxy.h"

#define CONNECTION_MANAGER_V1 "urn:schemas-upnp-org:service:ConnectionManager:1"
#define CONNECTION_MANAGER_V2 "urn:schemas-upnp-org:service:ConnectionManager:2"
#define RENDERING_CONTROL_V1  "urn:schemas-upnp-org:service:RenderingControl:1"
#define RENDERING_CONTROL_V2  "urn:schemas-upnp-org:service:RenderingControl:2"
#define AV_TRANSPORT_V1       "urn:schemas-upnp-org:service:AVTransport:1"
#define AV_TRANSPORT_V2       "urn:schemas-upnp-org:service:AVTransport:2"

G_DEFINE_TYPE (MediaRendererProxy,
               media_renderer_proxy,
               GUPNP_TYPE_DEVICE_PROXY);

struct _MediaRendererProxyPrivate {
        GUPnPServiceProxy *connection_manager;
        GUPnPServiceProxy *rendering_control;
        GUPnPServiceProxy *av_transport;
};

static void
media_renderer_proxy_init (MediaRendererProxy *proxy)
{
        /*GUPnPDeviceInfo *info;
        GUPnPServiceInfo *service_info;

        info = GUPNP_DEVICE_INFO (proxy);*/

        proxy->priv = G_TYPE_INSTANCE_GET_PRIVATE (proxy,
                                                   TYPE_MEDIA_RENDERER_PROXY,
                                                   MediaRendererProxyPrivate);

        /* Connection Manager * /
        service_info = gupnp_device_info_get_service (info,
                                                      CONNECTION_MANAGER_V1);
        if (service_info == NULL) {
                        service_info = gupnp_device_info_get_service
                                                      (info,
                                                       CONNECTION_MANAGER_V2);
        }
        proxy->priv->connection_manager = GUPNP_SERVICE_PROXY (service_info);

        / * Rendering Control * /
        service_info = gupnp_device_info_get_service (info,
                                                      RENDERING_CONTROL_V1);
        if (service_info == NULL) {
                        service_info = gupnp_device_info_get_service
                                                      (info,
                                                       RENDERING_CONTROL_V2);
        }
        proxy->priv->rendering_control = GUPNP_SERVICE_PROXY (service_info);

        / * AV Transport * /
         service_info = gupnp_device_info_get_service (info, AV_TRANSPORT_V1);

        if (service_info == NULL) {
                        service_info = gupnp_device_info_get_service
                                                      (info,
                                                       AV_TRANSPORT_V2);
        }

        proxy->priv->av_transport = GUPNP_SERVICE_PROXY (service_info);*/
}

static void
media_renderer_proxy_dispose (GObject *object)
{
        GObjectClass       *gobject_class;
        MediaRendererProxy *proxy;

        proxy = MEDIA_RENDERER_PROXY (object);

        if (proxy->priv->connection_manager) {
                g_object_unref (proxy->priv->connection_manager);
                proxy->priv->connection_manager = NULL;
        }

        if (proxy->priv->rendering_control) {
                g_object_unref (proxy->priv->rendering_control);
                proxy->priv->rendering_control = NULL;
        }

        if (proxy->priv->av_transport) {
                g_object_unref (proxy->priv->av_transport);
                proxy->priv->av_transport = NULL;
        }

        gobject_class = G_OBJECT_CLASS (media_renderer_proxy_parent_class);
        gobject_class->dispose (object);
}

static void
media_renderer_proxy_class_init (MediaRendererProxyClass *klass)
{
        GObjectClass *object_class;

        object_class = G_OBJECT_CLASS (klass);

        object_class->dispose = media_renderer_proxy_dispose;

        g_type_class_add_private (klass, sizeof (MediaRendererProxyPrivate));
}

