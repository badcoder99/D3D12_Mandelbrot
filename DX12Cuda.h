#pragma once
#include <cuda_runtime.h>
#include <windows.h>
#include "d3dx12.h"
#include "Vertex.h"

using Microsoft::WRL::ComPtr;

inline void ThrowIfFailed(HRESULT hr) {
   if (FAILED(hr)) {
      throw std::runtime_error("HRESULT failed");
   }
}

class DX12Cuda {
public:
   DX12Cuda(UINT width, UINT height);
   ~DX12Cuda();

   void OnInit();
   void OnRender();
   void OnDestroy();
   
private:
   UINT width;
   UINT height;
   float aspectRatio;
};

