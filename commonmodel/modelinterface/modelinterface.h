#ifndef MODELINTERFACE_H
#define MODELINTERFACE_H

#include <memory>
#include <stdexcept>

#include <protocolGraph/ProtocolGraph.h>
#include <utils/units.h>

#include "commonmodel/mappinginterface/mappinginterface.h"
#include "commonmodel/modelinterface/componentinterface.h"
#include "commonmodel/plugininterface/pluginabstractfactory.h"

class ModelInterface {
public:
    typedef enum MovementType_ {
        continuous = 1,
        discrete = 2
    } MovementType;

    virtual ~ModelInterface(){}

    virtual bool canDoMovement(unsigned long mask) = 0;
    virtual std::shared_ptr<MappingInterface> findProtocolRelation(std::shared_ptr<ProtocolGraph> protocol) throw(std::invalid_argument) = 0;

    virtual std::shared_ptr<ComponentInterface> getComponent(int virtualContainer) throw(std::invalid_argument) = 0;

    virtual void loadContainer(int containerId, units::Volume volume) throw(std::invalid_argument) = 0;

    virtual units::Time transferLiquid(int sourceId, int targetId,  units::Volume volume) throw(std::invalid_argument) = 0;
    virtual void stopTransferLiquid(int sourceId, int targetId) throw(std::invalid_argument) = 0;

    virtual units::Time mix(int sourceId1, int sourceId2, int targetId,  units::Volume volume1, units::Volume volume2) throw(std::invalid_argument) = 0;
    virtual void stopMix(int sourceId1, int sourceId2, int targetId) throw(std::invalid_argument) = 0;

    virtual void setContinuousFlow(int sourceId, int targetId,  units::Volumetric_Flow rate) = 0;
    virtual void setContinuousFlow(const std::vector<int> & containersIds,  units::Volumetric_Flow rate) throw(std::invalid_argument) = 0;

    virtual void stopContinuousFlow(int sourceId, int targetId) = 0;
    virtual void stopContinuousFlow(const std::vector<int> & containersIds) throw(std::invalid_argument) = 0;
    virtual void processFlows() throw(std::runtime_error) = 0;

    virtual void updatePluginFactory(std::shared_ptr<PluginAbstractFactory> factory) = 0;

};
#endif // MODELINTERFACE_H
