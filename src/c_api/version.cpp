#include "main/version.h"

#include "c_api/helpers.h"
#include "c_api/ryu.h"

char* kuzu_get_version() {
    return convertToOwnedCString(ryu::main::Version::getVersion());
}

uint64_t kuzu_get_storage_version() {
    return ryu::main::Version::getStorageVersion();
}
