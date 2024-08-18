# Competitive Programming Solutions

Welcome to my competitive programming solutions repository!
Here you'll find C/C++ solutions for various events and platforms.

## Platforms

- [AtCoder](https://atcoder.jp)
- [CSES](https://cses.fi/problemset/)
- [Codeforces](https://codeforces.com)
- [France-IOI](https://www.france-ioi.org/algo/chapters.php)

## Events

- [ICPC](https://icpc.global)
- [IEEEXtreme](https://ieeextreme.org)
- [Winter Cup](https://www.facebook.com/INSATWinterCup/)

## How to Get Started

### Prerequisites

To run the solutions in this repository, you'll need the following tools:

- A `C/C++` compiler like `gcc`.
- A `C/C++` debugger such as `gdb` (optional).
- `CMake` and `ninja` for managing binaries.

### Setup Instructions

This project uses `CMake` to compile all solution files into a separate build directory, typically named `build`. In my configuration, the default directory is `.build`, but you can change this in `CMakePresets.json`.

To run a solution, you'll need to *configure* and *build* the project:

- `CMake` will recursively scan the repository for all `cpp` files during the *configure* step.
- It will then compile these files during the *build* step, placing the binaries in `.build/default/bin`.
- Binaries are named in the format: `<directory_name>--<filename>`.

`CMake` presets simplify this process, allowing you to configure and build the project with predefined settings. The repository currently includes a `default` preset for your convenience.

### Running Solutions

There are different ways to execute solutions depending on your editor or IDE:

- **Visual Studio Code:**  
  Install the [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) extension. You'll see new icons in the status bar, allowing you to choose a preset, build the project, and run a solution with just a few clicks.

- **CLion:**  
  CLion should automatically detect the `CMake` configuration. To run a solution, simply click the green *Run* button in the top-right corner of the editor.

- **Other Editors/IDEs:**  
  Refer to your editor's documentation for `CMake` integration instructions.

- **Terminal:**  
  If your editor/IDE doesn't support `CMake` integration, you can use the terminal commands:
  - First-time setup: `cmake --preset default`.
  - Build the project: `cmake --build --preset default`.
  - Run a solution: `./.build/default/bin/<target_name>`.

## Reproducing This Setup in Another Repository

### CMake Configuration

The `CMake` setup is managed through two key files: `CMakeLists.txt` and `CMakePresets.json`.

- `CMakeLists.txt`: Configures how `CMake` detects source files and assigns target names to binaries, allowing you to run solutions without navigating to the binary's directory.

- `CMakePresets.json`: Configures the build directory location, generator, and other settings.

To replicate this setup, copy these two files to your new repository and customize them as needed.

### Visual Studio Code Configuration

For `VsCode`, I'm using the [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) extension. My customized status bar appearance is configured in `.vscode/settings.json`. Copy this file to your project to maintain the same appearance. You can learn more about configuring the status bar for this extension [here](https://github.com/microsoft/vscode-cmake-tools/blob/main/docs/cmake-options-configuration.md).

## Report an issue with a solution

Generally speaking, I include solutions in this repository that have been submitted and accepted.
However, there may be instances where solutions were not accepted or the version is outdated.
If you encounter such issues, please feel free to open an issue in this repository.

Happy coding! 🚀
