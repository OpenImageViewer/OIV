#pragma once
#include "../API/defs.h"
#include <Image.h>


namespace OIV
{
    class IPictureRenderer
    {
    public:
        virtual double Zoom(double percentage,int x, int y) = 0;
        virtual int Pan(double x, double y) = 0;
        virtual int LoadFile(void* buffer, std::size_t size, char* extension, bool onlyRegisteredExtension, ImageHandle& handle) = 0;
        virtual ResultCode UnloadFile(const ImageHandle handle) = 0;
        virtual ResultCode DisplayFile(const ImageHandle handle, const OIV_CMD_DisplayImage_Flags display_flags) = 0;

        virtual int Init() = 0;
        virtual int SetParent(std::size_t handle) = 0;
        virtual int Refresh() = 0;

        virtual int GetFileInformation(QryFileInformation& information) = 0;

        virtual IMCodec::Image* GetImage(ImageHandle handle) = 0;
        virtual int SetFilterLevel(OIV_Filter_type filter_level) = 0;
        virtual int GetTexelAtMousePos(int mouseX, int mouseY, double& texelX, double& texelY) = 0;
        virtual int SetTexelGrid(double gridSize) = 0;
        virtual int GetNumTexelsInCanvas(double &x, double &y) = 0;
        virtual int SetClientSize(uint16_t width, uint16_t height) = 0;
        virtual ResultCode AxisAlignTrasnform(const OIV_AxisAlignedRTransform transform) = 0;
        virtual ~IPictureRenderer() {}
        virtual ResultCode SetZoomScrollState(const OIV_CMD_ZoomScrollState_Request* zoom_scroll_state) = 0;
    };
}
