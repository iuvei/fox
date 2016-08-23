
#ifndef THREAD_H_
#define THREAD_H_
#pragma once

// 线程对象
class CThread
{
	// 函数定义
protected:
	// 构造函数
	CThread();
	// 析构函数
	virtual ~CThread();

	// 接口函数
public:
	// 获取状态
	virtual bool IsRuning();
	// 启动线程
	virtual bool StartThread();
	// 终止线程
	virtual bool ConcludeThread(DWORD dwMillSeconds);

	// 功能函数
public:
	// 线程标识
	UINT GetThreadID() { return m_uThreadID; }
	// 线程句柄
	HANDLE GetThreadHandle() { return m_hThreadHandle; }
	// 投递消息
	LRESULT PostThreadMessage(UINT uMessage, WPARAM wParam, LPARAM lParam);

	// 事件函数
protected:
	// 运行事件
	virtual bool OnEventThreadRun() { return true; }
	// 开始事件
	virtual bool OnEventThreadStrat() { return true; }
	// 终止事件
	virtual bool OnEventThreadConclude() { return true; }

	// 内部函数
private:
	// 线程函数
	static unsigned __stdcall ThreadFunction(LPVOID pThreadData);

	// 状态变量
private:
	volatile bool m_bRun; // 运行标志

	// 线程变量
private:
	UINT m_uThreadID; // 线程标识
	HANDLE m_hThreadHandle;	// 线程句柄
};

#endif // THREAD_H_