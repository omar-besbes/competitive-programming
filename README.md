# Competitive Programming Solutions

Hey there! 👋 Welcome to my repository where I keep my C/C++ solutions for various competitive programming events and platforms.

## Solutions

All solutions are in the [`solutions` directory](./solutions).

### Platforms I Use

You can find my solutions for problems from these platforms:

- <a href="https://atcoder.jp" target="_blank">AtCoder</a> -
[Solutions](./solutions/AtCoder)
- <a href="https://cses.fi/problemset/" target="_blank">CSES</a> -
[Solutions](./solutions/CSES)
- <a href="https://codeforces.com" target="_blank">Codeforces</a> -
[Solutions](./solutions/Codeforces)
- <a href="https://www.france-ioi.org/algo/chapters.php" target="_blank">France-IOI</a> -
[Solutions](./solutions/France-IOI)

### Events I Compete In

These are some of the competitive programming events I’ve participated in:

- <a href="https://icpc.global" target="_blank">ICPC</a> -
[Solutions](./solutions/ICPC)
- <a href="https://ieeextreme.org" target="_blank">IEEEXtreme</a> -
[Solutions](./solutions/IEEEXtreme)
- <a href="https://www.facebook.com/INSATWinterCup/" target="_blank">Winter Cup</a> -
[Solutions](./solutions/WinterCup)

## Getting started

To run the solutions in this repository, you'll need the following tools:

- A `C/C++` compiler like `gcc`.
- A `C/C++` debugger such as `gdb` (optional).
- `CMake` and `ninja` for managing binaries.

> [!Note]
>
> `VSCode` users don't have to to use CMake/Ninja anymore.  
> Just clone the project and you should be able to run/debug the active file directly
> from the run/debug button in the top right corner.
>

## CMake/Ninja Setup Instructions

> [!Note]
>
> Why should I use `CMake` to use this repository ?
>
> Originally, I used `CMake` to keep the binaries (the files generated when you
> run/debug solutions) separate from the source files.
> Both `CLion` and `VSCode` support `CMake`, which was handy as I hadn’t settled on a
> specific editor at the time.  
> Later when I discovered that `VSCode` tasks and launch configurations could work
> without `CMake`, I switched to a simpler setup,
> while keeping `CMake` functionality for those who prefer it.
>
> To be clear, **`CMake` is not mandatory**. Feel free to run the solutions however you
> prefer (but you'll be on your own).
>

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
  - First-time setup: `cmake --preset default`
  - Build the project: `cmake --build --preset default`
  - Run a solution: `./.build/default/bin/<target_name>`

### Reproducing This Setup in Another Repository

#### CMake Configuration

The `CMake` setup is managed through two key files: `CMakeLists.txt` and `CMakePresets.json`.

- `CMakeLists.txt`: Configures how `CMake` detects source files and assigns target names to binaries, allowing you to run solutions without navigating to the binary's directory.

- `CMakePresets.json`: Configures the build directory location, generator, and other settings.

To replicate this setup, copy these two files to your new repository and adjust them as needed.

#### Visual Studio Code Configuration

For `VSCode`, I used to use the [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) extension. You may customize the status bar appearance in `.vscode/settings.json`. You can learn more about configuring the status bar for this extension [here](https://github.com/microsoft/vscode-cmake-tools/blob/main/docs/cmake-options-configuration.md).

## Report an issue with a solution

Generally speaking, I include solutions in this repository that have been submitted and accepted.
However, there may be instances where solutions were not accepted or the version is outdated.
If you encounter such issues, please feel free to open an issue in this repository.

Good luck with your problem solving! 🚀
