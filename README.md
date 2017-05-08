# Windows Message
## Outline
Most common condition, we may need some outer program to help us processing or distinguish something in our program. It becomes a problem if the program couldn't be combination together. The communication between two programs is important. We can use message on natvie platform to help us completing the communication problem.

## Our Environment
| Platform | System | Develop Tools| Language |
| :------: |:------:|:----:|:---:|
| Windows 7 | 64-bit | Qt 5.8 + VS2015 | c++ |

## Message on Windows
### Windows Message Classification
This [list][2] Provide the list of windows event list.
In this tutorial, we will only use [WM_COPYDATA][3]. This defination of windows message is "An application sends the WM_COPYDATA message to pass data to another application." defined by Microsoft.
There are still many windows message can provide us to achieve and implement our goal. 

## Using Windows Message on Qt
### Function to use
__NativeEvent__
This fuction can use to implement the native platform event. You can find the Qt Defination on [Qt NativeEvent][1]. **Be careful of it is a function chich support begined from Qt 5.0. Qt 4.0 is not available.**
This function is a portected member, you should declare and rewrite it in protected function.

## How To Use

1. You should link libary User32.lib, which should be exist on your Windows computer system. You can link it by using the syntax " #pragma comment(lib, "user32.lib")" on your header. *If you use Qt as your develop platform* , you can link this libary on the .pro file like adding this "LIBS += User32.lib" 

2. Include Windows.h on your program.

3. Syntax 

LRESULT WINAPI SendMessage( <br>
  _In_ HWND   hWnd, <br>
  _In_ UINT   Msg, <br>
  _In_ WPARAM wParam, <br>
  _In_ LPARAM lParam <br>

);

<br>
Find the defination on [MSDN Website][5]

**hWnd**
It is a handler to decide which window should receieve message

**Msg**
The message type we want to send to other window.
It is a type of message, in this tutoiral we use WM_COPYDATA.

*The next two parameter is additional information.* <br>
*You can find how to use this additional message by finding which type of message you want to send.*

**wParam**
It is an additional message information. 
On WM_COPYDATA type of message,
this parameter is a handle to the window passing the data. In this tutorial we use Qt function to help us find this handle, but it is OK if you just type NULL on it. I guess that the default handle is just right, and the default is the sender which we program we are implementing.


**IParam**
It is an additional message information. 
On WM_COPYDATA type of message,
this parameter is a pointer to [COPYDATASTRUCT][6] structure which contains the data to be passed. 

*COPYDATASTRUCT* have three parameters

| Type | Name | Defination |
|:--:|:--:|:--:|
| ULONG_PTR | dwData | It is a unsinged long type for pointer precision. You can defined it as the unsigned long number you wanted. Presumably dwData is a method you can check the bridge between sender and receiver. |
| DWORD | cbData |  A 32-bit unsigned integer. The range is 0 through 4294967295 decimal.  Here is to decide the data size. |
| PVOID | lpData | The pointer of the cbData. | 

The data type can be found in [Windows Data Types][7]. <br>



## Reference Tutorial
[Qt 進程通訊][4]

[1]: http://doc.qt.io/qt-5/qwidget.html#nativeEvent  "Native Event"
[2]: https://wiki.winehq.org/List_Of_Windows_Messages "List of WM"
[3]: https://msdn.microsoft.com/en-us/library/windows/desktop/ms649011(v=vs.85).aspx "MSDN Defination"
[4]: http://blog.csdn.net/liang19890820/article/details/50589404 "Message between Qt Process"
[5]: https://msdn.microsoft.com/zh-tw/library/windows/desktop/ms644950(v=vs.85).aspx "SendMessage"
[6]: https://msdn.microsoft.com/en-us/library/windows/desktop/ms649010(v=vs.85).aspx  "COPYDATASTRUCT"
[7]: https://msdn.microsoft.com/en-us/library/windows/desktop/aa383751(v=vs.85).aspx#LONG_PTR  "Windows Data Types"