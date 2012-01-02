/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * FtdiDmxPlugin.h
 * The FTDI usb chipset DMX plugin for ola
 * Copyright (C) 2011 Rui Barreiros
 */

#ifndef PLUGINS_FTDIDMX_FTDIDMXPLUGIN_H_
#define PLUGINS_FTDIDMX_FTDIDMXPLUGIN_H_

#include <string>
#include <vector>

#include "olad/Plugin.h"
#include "ola/plugin_id.h"

#include "plugins/ftdidmx/FtdiDmxDevice.h"

namespace ola {
namespace plugin {
namespace ftdidmx {

using ola::PluginAdaptor;
typedef vector<FtdiDmxDevice*> FtdiDeviceVector;

class FtdiDmxPlugin : public Plugin {
 public:
  explicit FtdiDmxPlugin(PluginAdaptor *plugin_adaptor);

  ola_plugin_id Id() const { return OLA_PLUGIN_FTDIDMX; }
  string Name() const { return PLUGIN_NAME; }
  string PluginPrefix() const { return PLUGIN_PREFIX; }

  string Description() const;

  void DeviceRemoved(FtdiDmxDevice *device);
  void AddDevice(FtdiDmxDevice *device);
  void DeleteDevice(FtdiDmxDevice *device);

  static const char DEFAULT_FREQUENCY[];
  static const char K_FREQUENCY[];

 private:
  bool StartHook();
  bool StopHook();
  bool SetDefaultPreferences();
  unsigned int GetFrequency();

  FtdiDeviceVector m_devices;

  static const char PLUGIN_NAME[];
  static const char PLUGIN_PREFIX[];
};
}
}
}

#endif  // PLUGINS_FTDIDMX_FTDIDMXPLUGIN_H_
