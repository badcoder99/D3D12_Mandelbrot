#pragma once
#include <aclapi.h>
#include <cassert>

#pragma comment(lib, "advapi32.lib")

class WindowsSecurityAttributes {
public:
   WindowsSecurityAttributes();
   ~WindowsSecurityAttributes();
   SECURITY_ATTRIBUTES * operator&();

private:
   SECURITY_ATTRIBUTES m_winSecurityAttributes;
   PSECURITY_DESCRIPTOR m_winPSecurityDescriptor;
};

