# TasQ Application

## File Structure
```
/                       Project Root
├─ lib/                     Contains required libraries
│  ├─ bin/                      Binaries for libraries [gitignored]
│  ├─ include/                  Headers for libraries  [gitignored]
│  ├─ lib/                      DLLs for libraries     [gitignored]
├─ src/                     Source code
│  ├─ net/                     Network code to communicate with server
│  ├─ models/                  Data models and middleware
│  ├─ widgets/                 Custom UI widgets
│  │  ├─ my_widget/                Widget subfolder
│  │  │  ├─ my_widget.cpp              Widget source file
│  │  │  ├─ my_widget.h                Widget header
│  │  │  ├─ my_widget.ui               Widget UI file
│  │  │  ├─ ui_mywidget.h              Generated header from ui file, using uic [gitignored]
│  ├─ main.cpp                 Entry point
├─ test/                     Testing code
│  ├─ net/                     Tests for network code
│  ├─ models/                  Test for data models and middleware
│  ├─ widgets/                 Test for custom UI widgets
├─ cmakelists.txt           cmake build configuration
```