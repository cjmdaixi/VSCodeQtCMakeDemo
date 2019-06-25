# CMake-based Qt project in VSCode

This demo shows how to code and debug CMake-based Qt application in VSCode. It's actually quite simple. What I did including three things:

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
    "environment": [
        {"name": "Path", "value": "${env:Path};${env:Qt5_DIR}/bin"}
    ],
    ```

    This add the Qt's bin folder to the application's running path.

