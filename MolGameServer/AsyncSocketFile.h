#if !defined(AFX_ASYNCSOCKETFILE_H__7D02E33C_FB13_49DB_8012_C19588F90E1E__INCLUDED_)
#define AFX_ASYNCSOCKETFILE_H__7D02E33C_FB13_49DB_8012_C19588F90E1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AsyncSocketFile.h : header file
//

#include <afxsock.h>
#include "MolNet/MolMutex.h"

#define IDD_TIMER_DEBUG_SERVER 9009

#pragma pack(push, 1)
typedef struct
{
	BYTE type;          // 1 - �ļ�; 2 - ����; 3 - ��־; 4 - ����װ�ؽű�
	int totalCount;              // �ʼ��ܵĸ���
	char name[256];
	unsigned long size;
}mylogonpacket;
#pragma pack(pop)

/////////////////////////////////////////////////////////////////////////////
// CAsyncSocketFile command target

/** 
 * ���ڴ�����ļ��ṹ
 */
struct FileStruct
{
	unsigned long totalSize;
	unsigned long curSize;
};

class CMolServerDlg;

class CAsyncSocketFile : public CAsyncSocket
{
// Attributes
public:
	CFile m_cFile;
	CString m_filePath,m_dirPath;
	CString m_password;
	bool m_isStartRev;
	bool m_isLoginOk;
	FileStruct m_curFile;
	int m_totalFileCount;
	DWORD m_curTime;
	CMolServerDlg *m_mainDlg;
	Mutex m_MesLock;
// Operations
public:
	CAsyncSocketFile();
	virtual ~CAsyncSocketFile();

	/// ����������
	inline void SetMainDlg(CMolServerDlg *dlg) { m_mainDlg = dlg; }
	/// �����ļ�����
	inline void SetWorkFileCount(int count) { m_totalFileCount = count; }

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAsyncSocketFile)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CAsyncSocketFile)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
public:
	BOOL OpenFile(LPCTSTR lpszPath);
	BOOL SendFile(LPCTSTR lpszPath);
	BOOL SendDirection(LPCTSTR lpszPath);
	/// ���õ�¼����
	void SetPassword(CString pw);
	/// �õ���ǰʱ��
	inline DWORD GetCurTime(void) { return m_curTime; }
	/// ���õ�ǰʱ��
	inline void SetCurTime(DWORD time) { m_curTime = time; }
	/// ��⵱ǰ�Ƿ��¼�ɹ�
	inline bool IsLoginOk(void) { return m_isLoginOk; }
	/// ��ʼ����Ŀ¼
	void StartSendDireciton(void);
	/// ���ʹ�����Ϣ
	void SendLogInfo(CString info);
	/// ��ȡ����Ŀ¼���ļ�����
	int GetWorkFileCount(void);

public:
	void CloseFile();
public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnSend( int nErrorCode);
	virtual void OnClose(int nErrorCode);
};

extern CAsyncSocketFile* m_cAsyncSocketFile;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASYNCSOCKETFILE_H__7D02E33C_FB13_49DB_8012_C19588F90E1E__INCLUDED_)