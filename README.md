# Data Structures & Algorithms — C++ Solutions

![Language: C++]

A curated collection of Data Structures & Algorithms solved in C++ with a consistent layout and small helper scripts to speed up adding and running problems.

This repo is organized so you can browse topics by category and difficulty, add new problems quickly, and run any solution from the root.

Why this repo

- Focused: each problem lives in its own folder with a single `index.cpp` and a problem `Readme.md`.
- Reproducible: `run.sh` compiles and runs solutions for you.
- Scalable: `new.sh` scaffolds new problems in the correct structure.

Repository layout

`<topic>/<difficulty>/<problem-name>/`

- `index.cpp` — solution source file
- `Readme.md` — problem statement, approach, complexity

Top-level helper files

- `new.sh` — scaffold a new problem folder from a title
- `run.sh` — compile and run a problem from repo root

Example

```
arrays/
  easy/
    largest-element-in-an-array/
      index.cpp
      Readme.md
    second-largest-element-without-sorting/
      index.cpp
      Readme.md
dp/
binary-search/
bit-manipulation/
template/
  index.cpp
  Readme.md
run.sh
new.sh
README.md

```

Getting started

1. Clone the repo:

```bash
git clone <your-repo-url>
cd data-structure-algorithm
```

2. Make helper scripts executable:

```bash
chmod +x new.sh run.sh
```

3. (Optional) Add a shell alias for convenient runs:

```bash
echo "alias run='$PWD/run.sh'" >> ~/.zshrc
source ~/.zshrc
```

Add a new problem

```bash
./new.sh "arrays/easy/Find Missing Number"
```

This creates a kebab-cased folder `arrays/easy/find-missing-number/` with `index.cpp` and `Readme.md` prefilled.

Run solutions

From the repository root you can compile and run any problem:

```bash
./run.sh arrays/easy/find-missing-number
# or, with the alias if you added it:
run arrays/easy/find-missing-number
```

You can also point `run.sh` at a specific source file:

```bash
./run.sh arrays/easy/problem/index.cpp
```

Best practices

- Keep `index.cpp` focused on solving the problem — include input/output examples in the problem `Readme.md`.
- Do not commit compiled binaries named `index` or `index.exe`.
- Add algorithm explanation and time/space complexity to each problem's `Readme.md`.

Recommended `.gitignore`

```
# Compiled binaries
index
*/index

# C++ build files
*.o
*.out
a.out

# IDE
.vscode/
.idea/

# OS
.DS_Store

# temp
*~
*.log
```

Contributing

1. Create an issue or pick an open problem.
2. Run `./new.sh "topic/difficulty/Problem Name"` to scaffold your solution.
3. Implement `index.cpp`, add examples and explanation to the problem `Readme.md`.
4. Open a pull request with a clear title and short description.

License & Contact

This repository is available under the MIT License — add `LICENSE` if you want an explicit license file.
