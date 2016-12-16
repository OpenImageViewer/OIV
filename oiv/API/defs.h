
#pragma once
#include <cwchar>
#include <stdint.h>

#ifdef OIV_NO_CLIENT_BUILD
    #define OIV_EXPOSE_FUNCTION __declspec(dllexport)
#else
    #define OIV_EXPOSE_FUNCTION __declspec( dllimport )
#endif

extern "C"
{

#ifdef UNICODE
    typedef wchar_t OIVCHAR;
#else
    typedef char OIVCHAR;
#endif



    enum CommandExecute
    {
          CE_NoOperation
        , CE_Init
        , CE_Destory
        , CE_LoadFile
        , CE_Zoom
        , CE_Pan
        , CE_FilterLevel
        , CE_Refresh
        , CE_GetFileInformation
        , CE_TexelAtMousePos
        , CE_TexelGrid
        , CMD_SetClientSize
        , CMD_GetNumTexelsInCanvas
        , OIV_CMD_Destroy
    };

    
    enum ResultCode
    {
          RC_Success
        , RC_InvalidParameters
        , RC_FileNotFound
        , RC_FileNotSupported
        , RC_WrongDataSize
        , RC_NotInitialized
        , RC_AlreadyInitialized
        , RC_WrongParameters
        , RC_UknownError = 0xFF

    };

#pragma pack(push, 1) 
    //-------Command Structs-------------------------

    struct CmdNull
    {
        
    };

    struct CmdSetClientSizeRequest
    {
        uint16_t width;
        uint16_t height;
    };

    struct CmdGetNumTexelsInCanvasResponse
    {
        double width;
        double height;
    };

    struct CmdRequestTexelGrid
    {
        double gridSize;
    };

    struct CmdRequestTexelAtMousePos
    {
        int x;
        int y;
    };
    
    struct CmdResponseTexelAtMousePos
    {
        double x;
        double y;
    };

    struct CmdRequestFilter
    {
        int filterLevel;
    };

    struct CmdDataZoom
    {
        double amount;
        int zoomX;
        int zoomY;
    };

    struct CmdResponseLoad
    {
        double loadTime;
        int width;
        int height;
        int bpp;
    };

    struct CmdDataPan
    {
        double x;
        double y;
    };

    struct CmdDataLoadFile
    {
        static const int EXTENSION_SIZE = 16;
        size_t length;
        void* buffer;
        char extension[EXTENSION_SIZE];
        bool onlyRegisteredExtension;
    };

    struct CmdDataInit
    {
        size_t parentHandle;
    };

  /*  struct CmdDataClientMetrics
    {
        int width;
        int height;
    };*/

    //-------Query Structs-------------------------


    struct QryFileInformation
    {
        int width;
        int height;
        int bitsPerPixel;
        int numMipMaps;
        int numChannels;
        int imageDataSize;
        int rowPitchInBytes;
        int hasTransparency;
    };

#pragma pack(pop) 

}
