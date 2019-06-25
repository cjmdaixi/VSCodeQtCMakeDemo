# CMake-based Qt project in VSCode

This demo shows how to code and debug CMake-based Qt application in VSCode. It's actually quite simple. 

Before compiling & running this demo, something should be configures:

1. Set system environmental variable `Qt5_DIR` to be the absolute path of your Qt installation.
2. Install VSCode and relating extensions:
   1. CMake Tools
   2. C/C++ (It might be installed by default).

What I did including the following things:

1. Configure the global includePath of VSCode to support intelligence of Qt classes. This is done by configuring the VSCode's global setting file: settings.json by adding things below:

    ```json
    "[cpp]": {
        "editor.quickSuggestions": true
    },
    "[c]": {
        "editor.quickSuggestions": true
    },
    "C_Cpp.default.includePath": [
        "${env:Qt5_DIR}/include",
        "${workspaceFolder}/src"
    ],
    ```

2. Configure the launch parameter of the project. This is done by editing the launch.json of the project:

    ```json
    "program": "${command:cmake.launchTargetPath}",
    "environment": [
        {"name": "Path", "value": "${env:Path};${env:Qt5_DIR}/bin"}
    ],
    ```

    `${command:cmake.launchTargetPath}` will be evaluated to return the path of your CMake target. It avoids hard-coding the executable path. And `environment` adds the Qt's bin folder to the application's running path.

