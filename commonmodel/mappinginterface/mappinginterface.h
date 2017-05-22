#ifndef MAPPINGINTERFACE_H
#define MAPPINGINTERFACE_H

#include <cstdarg>
#include <memory>
#include <stdexcept>
#include <string>

#include <protocolGraph/ProtocolGraph.h>

class MappingInterface {
public:
    virtual ~MappingInterface(){}

    virtual bool findRelation(std::shared_ptr<ProtocolGraph> protocol,int nargs, ...) throw(std::invalid_argument) = 0;
    virtual int getMappedComponent(const std::string & virtualContainer) = 0;
};
#endif // MAPPINGINTERFACE_H
