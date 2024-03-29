![FDF logo](.media/fdf_logo.png)

![Grade badge](https://img.shields.io/badge/105_%2F_100-004d40?label=final%20grade&labelColor=151515&logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIGhlaWdodD0iMjRweCIgdmlld0JveD0iMCAwIDI0IDI0IiB3aWR0aD0iMjRweCIgZmlsbD0iI0ZGRkZGRiI+PHBhdGggZD0iTTAgMGgyNHYyNEgweiIgZmlsbD0ibm9uZSIvPjxwYXRoIGQ9Ik0xMiAxNy4yN0wxOC4xOCAyMWwtMS42NC03LjAzTDIyIDkuMjRsLTcuMTktLjYxTDEyIDIgOS4xOSA4LjYzIDIgOS4yNGw1LjQ2IDQuNzNMNS44MiAyMXoiLz48L3N2Zz4=) ![Language Badge](https://img.shields.io/badge/C-fe428e?logo=C&label=language&labelColor=151515) ![Norminette Badge](https://img.shields.io/badge/passing-brightgreen?logo=42&label=norminette&labelColor=151515) ![Library Badge](https://img.shields.io/badge/my_own_libft-004d40?logo=GitHub&label=library%20used&labelColor=151515) ![Library Badge](https://img.shields.io/badge/MLX42-004d40?logo=GitHub&label=library%20used&labelColor=151515) ![Library badge](https://img.shields.io/badge/math_library-004d40?label=library%20used&labelColor=151515&logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIGhlaWdodD0iMjRweCIgdmlld0JveD0iMCAwIDI0IDI0IiB3aWR0aD0iMjRweCIgZmlsbD0iI0ZGRkZGRiI+PHBhdGggZD0iTTAgMGgyNHYyNEgweiIgZmlsbD0ibm9uZSIvPjxwYXRoIGQ9Ik0xOCA0SDZ2Mmw2LjUgNkw2IDE4djJoMTJ2LTNoLTdsNS01LTUtNWg3eiIvPjwvc3ZnPg==)

# FDF

This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).
The only external library that is allowed is `MLX42`, available [here](https://github.com/codam-coding-college/MLX42) on GitHub, created and maintained by [Codam](https://www.codam.nl/en/), member of the [42 Network](https://www.42network.org/). 
The full subject can be found [here](.media/en.subject.pdf).

# Downloading and compiling the project

Clone the library and use `make` to compile
```
git clone https://github.com/theozanchi/42_Berlin_FDF/tree/main
cd 42_Berlin_FDF
make
```

![Compilation screenshot](.media/compilation_complete_screenshot.png)

# Running the program

Program expects a `.fdf` file as an entry parameter
```
./fdf maps/42.fdf
```

The function renders an isometric projection of the map passed as a parameter:
![42.fdf screenshot](.media/42_screenshot.png)

If colors are encoded in the entry file, they are also rendered:
![t1.fdf screenshot](.media/t1_screenshot.png)
