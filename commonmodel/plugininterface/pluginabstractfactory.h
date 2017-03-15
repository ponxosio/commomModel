#ifndef PLUGINABSTRACTFACTORY_H
#define PLUGINABSTRACTFACTORY_H

#include <memory>

#include "commonmodel/plugininterface/heaterpluginproduct.h"
#include "commonmodel/plugininterface/lightpluginproduct.h"
#include "commonmodel/plugininterface/odsensorpluginproduct.h"
#include "commonmodel/plugininterface/pumppluginproduct.h"
#include "commonmodel/plugininterface/stirerpluginproduct.h"
#include "commonmodel/plugininterface/valvepluginproduct.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"

class PluginAbstractFactory {
public:
    PluginAbstractFactory(){}
    virtual ~PluginAbstractFactory(){}

    virtual std::shared_ptr<HeaterPluginProduct> makeHeater(const PluginConfiguration & configuration) = 0;
    virtual std::shared_ptr<LightPluginProduct> makeLight(const PluginConfiguration & configuration) = 0;
    virtual std::shared_ptr<OdSensorPluginProduct> makeOdSensor(const PluginConfiguration & configuration) = 0;
    virtual std::shared_ptr<PumpPluginProduct> makePump(const PluginConfiguration & configuration) = 0;
    virtual std::shared_ptr<StirerPluginProduct> makeStirer(const PluginConfiguration & configuration) = 0;
    virtual std::shared_ptr<ValvePluginProduct> makeValve(const PluginConfiguration & configuration) = 0;

};

#endif // PLUGINABSTRACTFACTORY_H
