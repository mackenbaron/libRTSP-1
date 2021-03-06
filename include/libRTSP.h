#pragma once
#ifdef LIBRTSP_EXPORTS
#define LIBRTSP_API __declspec(dllexport)
#else
#define LIBRTSP_API __declspec(dllimport)
#endif

#ifdef __cplusplus
#define LIBRTSPEXTERNC_HEAD extern "C" {
#define LIBRTSPEXTERNC_TILE }
#else
#define LIBRTSPEXTERNC_HEAD
#define LIBRTSPEXTERNC_TILE
#endif // __cplusplus

LIBRTSPEXTERNC_HEAD

typedef enum _RTSPProtocol
{
    RTSPProtocolUnspecified = 0,
    RTSPUsingTCP,
    RTSPUsingUDP
}RTSPProtocol;

// API for client usage begin

typedef void* RTSPClientHandle;

#define RTSPHANDLEISVALID(rtspClientHandle) NULL == (rtspClientHandle) ? false : true;

LIBRTSP_API unsigned int initializeDLLAsRTSPClient(void);

LIBRTSP_API unsigned int freeRTSPClinetDLL(void);

LIBRTSP_API RTSPClientHandle getNewRTSPHandle(void);

LIBRTSP_API void freeRTSPHandle(RTSPClientHandle* handle);

LIBRTSP_API unsigned int setRTSPURI(RTSPClientHandle handle, char* URI);

LIBRTSP_API unsigned int setRTSPProtocol(RTSPClientHandle handle, RTSPProtocol protocol);

LIBRTSP_API unsigned int setUserAgent(RTSPClientHandle handle, char* userAgent);

LIBRTSP_API unsigned int tryConnectToServer(RTSPClientHandle handle);

LIBRTSP_API unsigned int executeOPTIONS(RTSPClientHandle handle);

// API for client usage end

// API for server usage begin

LIBRTSP_API unsigned int initializeDLLAsRTSPServer(void);

LIBRTSP_API unsigned int freeRTSPServerDLL(void);

// API for serverusage end

LIBRTSPEXTERNC_TILE