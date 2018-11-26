#include "DX12Cuda.h"

using namespace Microsoft::WRL;

DX12Cuda::DX12Cuda(UINT width, UINT height) : width(width), height(height) {
   aspectRatio = static_cast<float>(width) / static_cast<float>(height);
}

~DX12Cuda::DX12Cuda() {
}


