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

## How to make this work ?

You need to have a `c/c++` compiler like `gcc` installed.

Optionally, you can install `cmake` to better manage binaries and easily choose to execute the solution you want.

### CMake

> [!NOTE]
> Make sure to install `ninja` as well to have better build times.

I am using `cmake` to compile all solution files in a single directory (separate from the source code).
By defaullt, this directory's name is `build` but if you are using `vscode` it will be `.build` (You can always change this in `vscode/settings.json`).

`cmake` will recursively scan the repository for all `cpp` files and compile them under `<build_dir>/bin`.
The binaries names will be in the following format: `<directory_name>--<filename>`.

Although, you could navigate to the wanted solution binary to execute it, `cmake` should be able to integrate with your editor.

- If you are using `vscode`, install [this](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) extension.
  You will have a new menu on the aside bar. This menu will have all of the solutions listed as well as other good stuff you can explore :).
- If you are using the `CLion`, it should pick up on the `cmake` config automatically.
  You can execute any solution by clicking on the green _run button_ on the top right corner of the editor.
- If you are using another text editor/IDE, please check their documentation on how to use `cmake`.

## Report an issue with a solution

Generally speaking, I include solutions in this repository that have been submitted and accepted.
However, there may be instances where solutions were not accepted or the version is outdated.
If you encounter such issues, please feel free to open an issue in this repository.

Happy coding! 🚀
