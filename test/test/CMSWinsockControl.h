// CMSWinsockControl.h : 由 Microsoft Visual C++ 创建的 ActiveX 控件包装类的声明

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CMSWinsockControl

class CMSWinsockControl : public CWnd
{
protected:
	DECLARE_DYNCREATE(CMSWinsockControl)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x248DD896, 0xBB45, 0x11CF, { 0x9A, 0xBC, 0x0, 0x80, 0xC7, 0xE7, 0xB7, 0x8D } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 特性
public:

// 操作
public:

	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long get_Protocol()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Protocol(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_RemoteHostIP()
	{
		CString result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_LocalHostName()
	{
		CString result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_LocalIP()
	{
		CString result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long get_SocketHandle()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString get__RemoteHost()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put__RemoteHost(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_RemotePort()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_RemotePort(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_LocalPort()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_LocalPort(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	short get_State()
	{
		short result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
		return result;
	}
	long get_BytesReceived()
	{
		long result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void Connect(VARIANT RemoteHost, VARIANT RemotePort)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &RemoteHost, &RemotePort);
	}
	void Listen()
	{
		InvokeHelper(0x41, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Accept(long requestID)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_EMPTY, NULL, parms, requestID);
	}
	void SendData(VARIANT data)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &data);
	}
	void GetData(VARIANT * data, VARIANT type, VARIANT maxLen)
	{
		static BYTE parms[] = VTS_PVARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_EMPTY, NULL, parms, data, &type, &maxLen);
	}
	void PeekData(VARIANT * data, VARIANT type, VARIANT maxLen)
	{
		static BYTE parms[] = VTS_PVARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_EMPTY, NULL, parms, data, &type, &maxLen);
	}
	void Close()
	{
		InvokeHelper(0x46, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Bind(VARIANT LocalPort, VARIANT LocalIP)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &LocalPort, &LocalIP);
	}
	CString get_RemoteHost()
	{
		CString result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_RemoteHost(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}


};
