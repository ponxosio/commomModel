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
#include "commonmodel/plugininterface/temperaturesensorproduct.h"
#include "commonmodel/plugininterface/luminiscencesensorproduct.h"
#include "commonmodel/plugininterface/fluorescencesensorproduct.h"
#include "commonmodel/plugininterface/volumesensorproduct.h"
#include "commonmodel/plugininterface/shakepluginproduct.h"
#include "commonmodel/plugininterface/centrifugatepluginproduct.h"
#include "commonmodel/plugininterface/electrophoresispluginproduct.h"

class PluginAbstractFactory {
public:
    virtual ~PluginAbstractFactory(){}

    virtual std::shared_ptr<HeaterPluginProduct> makeHeater(std::shared_ptr<PluginConfiguration> configuration) = 0;
    virtual std::shared_ptr<LightPluginProduct> makeLight(std::shared_ptr<PluginConfiguration> configuration) = 0;

    virtual std::shared_ptr<StirerPluginProduct> makeStirer(std::shared_ptr<PluginConfiguration> configuration) = 0;
    virtual std::shared_ptr<ShakePluginProduct> makeShaker(std::shared_ptr<PluginConfiguration> configuration) = 0;
    virtual std::shared_ptr<CentrifugatePluginProduct> makeCentrifugate(std::shared_ptr<PluginConfiguration> configuration) = 0;

    virtual std::shared_ptr<ElectrophoresisPluginProduct> makeElectrophorer(std::shared_ptr<PluginConfiguration> configuration) = 0;

    virtual std::shared_ptr<OdSensorPluginProduct> makeOdSensor(std::shared_ptr<PluginConfiguration> configuration) = 0;
    virtual std::shared_ptr<TemperatureSensorProduct> makeTemperatureSensor(std::shared_ptr<PluginConfiguration> configuration) = 0;
    virtual std::shared_ptr<LuminiscenceSensorProduct> makeLuminiscenseSensor(std::shared_ptr<PluginConfiguration> configuration) = 0;
    virtual std::shared_ptr<FluorescenceSensorProduct> makeFluorescenceSensor(std::shared_ptr<PluginConfiguration> configuration) = 0;
    virtual std::shared_ptr<VolumeSensorProduct> makeVolumeSensor(std::shared_ptr<PluginConfiguration> configuration) = 0;

    virtual std::shared_ptr<PumpPluginProduct> makePump(std::shared_ptr<PluginConfiguration> configuration) = 0;
    virtual std::shared_ptr<ValvePluginProduct> makeValve(std::shared_ptr<PluginConfiguration> configuration) = 0;

};

#endif // PLUGINABSTRACTFACTORY_H
