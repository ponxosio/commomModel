#ifndef MAPPINGINTERFACE_H
#define MAPPINGINTERFACE_H

#include <memory>
#include <string>

#include <protocolGraph/ProtocolGraph.h>

class MappingInterface {
public:
    virtual ~MappingInterface(){}

    virtual bool findRelation(std::shared_ptr<ProtocolGraph> protocol) = 0;
    virtual int getMappedComponent(const std::string & virtualContainer) = 0;
};
#endif // MAPPINGINTERFACE_H
