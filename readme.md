# TasQ Application

## File Structure
```
/                       Project Root
├─ lib/                     Contains required libraries
│  ├─ bin/                      Binaries for libraries [gitignored]
│  ├─ include/                  Headers for libraries  [gitignored]
│  ├─ lib/                      DLLs for libraries     [gitignored]
├─ include/                 Shared headers
│  ├─ net/                     Headers for network code
│  ├─ models/                  Headers for data models and middleware
│  ├─ widgets/                 Headers for Custom UI widgets
│  │  ├─ my_widget.h                Widget header
├─ src/                     Source code
│  ├─ net/                     Network code to communicate with server
│  ├─ models/                  Data models and middleware
│  ├─ widgets/                 Custom UI widgets
│  │  ├─ my_widget/                Widget subfolder
│  │  │  ├─ my_widget.cpp              Widget source file
│  │  │  ├─ my_widget.ui               Widget UI file
│  │  │  ├─ ui_mywidget.h              Generated header from ui file, using uic [gitignored]
│  ├─ main.cpp                 Entry point
├─ test/                     Testing code
│  ├─ net/                     Tests for network code
│  ├─ models/                  Test for data models and middleware
│  ├─ widgets/                 Test for custom UI widgets
├─ cmakelists.txt           cmake build configuration
```

## Building
### Qt UI Compiler path
In order to create the UI, `*.ui` files are compiled by Qt, using `uic`. Ensure that the Qt bin folder (`[QT INSTAL DIR]\[VERSION]\[Compiler]\bin`) is on the path.

### CMake Configuration
CMake needs the path to your Qt installation. This can be configured by adding `-DCMAKE_PREFIX_PATH=[Qt toolchain path]` to **CMake Options** in **File | Settings | Build, Execution, Deployment | CMake**.

![CMake options for a Qt project](https://resources.jetbrains.com/help/img/idea/2021.2/cl_qt_cmake_options.png)

### Build configuration
To ensure your application can find the binaries for required libraries, your build configuration should have the environment variable `PATH` set to `$PROJECT_DIR$/lib/bin`.

CLion configurations are included for **TasQ_Application** and **TasQ_Application_autogen** which include these settings.
