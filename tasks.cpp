/*

{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build debug",
            "type": "process",
            "command": "make",
            "args": [
                "PLATFORM=PLATFORM_DESKTOP",
                "BUILD_MODE=DEBUG"
            ],
            "windows": {
                "command": "C:/raylib/w64devkit/bin/mingw32-make.exe",
                "args": [
                    "RAYLIB_PATH=C:/raylib/raylib",
                    "PROJECT_NAME=${fileBasenameNoExtension}",
                    "OBJS=src/*.cpp",
                    "BUILD_MODE=DEBUG"
                ]
            },
            "osx": {
                "args": [
                    "PROJECT_NAME=${fileBasenameNoExtension}",
                    "OBJS=src/*.cpp",
                    "BUILD_MODE=DEBUG"
                ]
            },
            "linux": {
                "args": [
                    "PROJECT_NAME=${fileBasenameNoExtension}",
                    "DESTDIR=/home/linuxbrew/.linuxbrew",
                    "RAYLIB_LIBTYPE=SHARED",
                    "EXAMPLE_RUNTIME_PATH=/home/linuxbrew/.linuxbrew/lib",
                    "OBJS=src/*.cpp",
                    "BUILD_MODE=DEBUG"
                ]
            },
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "label": "build release",
            "type": "process",
            "command": "make",
            "args": [
                "PLATFORM=PLATFORM_DESKTOP"
            ],
            "windows": {
                "command": "C:/raylib/w64devkit/bin/mingw32-make.exe",
                "args": [
                    "RAYLIB_PATH=C:/raylib/raylib",
                    "PROJECT_NAME=${fileBasenameNoExtension}",
                    "OBJS=src/*.cpp"
                ]
            },
            "osx": {
                "args": [
                    "PROJECT_NAME=${fileBasenameNoExtension}",
                    "OBJS=src/*.cpp"
                ]
            },
            "linux": {
                "args": [
                    "PROJECT_NAME=${fileBasenameNoExtension}",
                    "DESTDIR=/home/linuxbrew/.linuxbrew",
                    "RAYLIB_LIBTYPE=SHARED",
                    "EXAMPLE_RUNTIME_PATH=/home/linuxbrew/.linuxbrew/lib",
                    "OBJS=src/*.cpp"
                ]
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "detail": "compiler: C:\\raylib\\w64devkit\\bin\\g++.exe"
        }
    ]
}




settings.json

{
	"files.exclude": {
		"**/.git": true,
		"**/.svn": true,
		"**/.hg": true,
		"**/CVS": true,
		"**/.DS_Store": true,
		"**/*.o": true,
		"**/*.exe": true,
	}
}




//// 
launch

{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
      "version": "0.2.0",
      "configurations": [
        {
          "name": "Debug",
          "type": "cppdbg",
          "request": "launch",
          "program": "${workspaceFolder}/${fileBasenameNoExtension}",
          "args": [],
          "stopAtEntry": false,
          "cwd": "${workspaceFolder}",
          "environment": [],
          "externalConsole": false,
          "MIMode": "gdb",
          "setupCommands": [
            {
              "description": "Enable pretty-printing for gdb",
              "text": "-enable-pretty-printing",
              "ignoreFailures": false
            }
          ],
          "windows": {
            "miDebuggerPath": "C:/raylib/w64devkit/bin/gdb.exe",
          },
          "osx": {
            "MIMode": "lldb"
          },
          "linux": {
            "miDebuggerPath": "/usr/bin/gdb",
          },
          "preLaunchTask": "build debug"
        },
        {
          "name": "Run",
          "type": "cppdbg",
          "request": "launch",
          "args": [],
          "stopAtEntry": false,
          "cwd": "${workspaceFolder}",
          "environment": [],
          "externalConsole": false,
          "program": "${workspaceFolder}/${fileBasenameNoExtension}",
          "MIMode": "gdb",
          "windows": {
            "program": "${workspaceFolder}/${fileBasenameNoExtension}.exe",
            "miDebuggerPath": "C:/raylib/w64devkit/bin/gdb.exe"
          },
          "osx": {
            "MIMode": "lldb"
          },
          "linux": {
            "miDebuggerPath": "/usr/bin/gdb"
          },
          "preLaunchTask": "build release",
        }
      ]
    }


c_cpp_prop ////////////////////////////////////////////////////////////////////////

{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "C:/raylib/raylib/src/**",
                "${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE",
                "GRAPHICS_API_OPENGL_33",
                "PLATFORM_DESKTOP"
            ],
            "compilerPath": "C:/raylib/w64devkit/bin/gcc.exe",
            "cStandard": "c99",
            "cppStandard": "c++14",
            "intelliSenseMode": "gcc-x64",
            "configurationProvider": "ms-vscode.makefile-tools"
        },
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/**",
                "/opt/homebrew/include"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE",
                "GRAPHICS_API_OPENGL_33",
                "PLATFORM_DESKTOP"
            ],
            "macFrameworkPath": [
                "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/System/Library/Frameworks"
            ],
            "compilerPath": "/usr/bin/clang",
            "cStandard": "c11",
            "cppStandard": "c++14",
            "intelliSenseMode": "clang-x64"
        },
        {
            "name": "Linux",
            "includePath": [
                "/home/linuxbrew/.linuxbrew/include",
                "${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE",
                "GRAPHICS_API_OPENGL_33",
                "PLATFORM_DESKTOP"
            ],
            "cStandard": "c11",
            "cppStandard": "c++14",
            "intelliSenseMode": "gcc-x64"
        }
    ],
    "version": 4
}



*/