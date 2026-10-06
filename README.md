# ICS 45C · hw1

This repository is your workspace for this assignment. It contains the files you will edit,
the build configuration, and nothing else; the assignment itself is described in class and
on the course site.

## Build and test

```
make          # build
make test     # run the local tests
make clean    # remove build output
```

## Layout

- `src/` – your implementation
- `gtest/` – your GoogleTest tests; `gtest/gtestmain.cpp` is provided, do not edit it
- `CMakeLists.txt`, `CMakePresets.json` – the build; `cmake --preset default && cmake --build build`
  does what `make` does

## Submit

Push your work to your own GitHub repository (this repository), then submit that repository
on Gradescope. Gradescope grades the files it finds in the repository, so commit and push
before submitting.
