// <Copyright Holder>. Copyright (C) <Copyright Year(s)>. <License>
#ifndef HEADER_LAPLACIAN_VERSION_H_INCLUDED
#define HEADER_LAPLACIAN_VERSION_H_INCLUDED

#ifdef __cplusplus
#   define EXTERNC extern "C"
#else
#   define EXTERNC
#endif

EXTERNC int laplacian_version_major();
EXTERNC int laplacian_version_minor();
EXTERNC int laplacian_version_patch();

#endif
