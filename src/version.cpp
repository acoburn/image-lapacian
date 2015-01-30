#include <laplacian/version.h>
#include "laplacianinfo.h"

EXTERNC int laplacian_version_major()
{ 
    return APPLICATION_VERSION_MAJOR; 
}

EXTERNC int laplacian_version_minor()
{
    return APPLICATION_VERSION_MINOR;
}

EXTERNC int laplacian_version_patch()
{
    return APPLICATION_VERSION_PATCH;
}
