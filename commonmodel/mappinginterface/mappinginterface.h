#ifndef MAPPINGINTERFACE_H
#define MAPPINGINTERFACE_H

#include <cstdarg>
#include <memory>
#include <stdexcept>
#include <string>

#include <protocolGraph/execution_interface/protocolsimulationinterface.h>
#include <protocolGraph/ProtocolGraph.h>

class MappingInterface {
public:
    virtual ~MappingInterface(){}

    virtual bool findRelation(std::shared_ptr<ProtocolSimulatorInterface> simulator,
                              std::string & errorMsg) throw(std::invalid_argument) = 0;
    virtual int getMappedComponent(const std::string & virtualContainer) = 0;

    virtual std::vector<int> getAllContainersUseInProtocol() = 0;
};
#endif // MAPPINGINTERFACE_H
