# DNA Alignment (Needleman–Wunsch)

Authors
- Juan Fernando Ruiz
- Louis Carrico-Braun (partner)

Description
Implements the Needleman–Wunsch global alignment algorithm to compute the optimal alignment and alignment distance (penalty) between two DNA sequences. The program uses dynamic programming and reconstructs the alignment from a scoring matrix.

Usage

Dependencies
- SFML is required: the source includes SFML headers, so SFML must be installed and available at compile-time and runtime.
- Boost (for running the unit tests) — install Boost libraries if you plan to build and run `test.cpp`.

Build and run examples
- Linux / macOS (g++ + system-installed SFML):
  g++ -std=c++17 main.cpp EDistance.cpp -o aligner -lsfml-graphics -lsfml-window -lsfml-system
  ./aligner <input_file>

- Windows (PowerShell) with MinGW/MSYS (example):
  g++ -std=c++17 main.cpp EDistance.cpp -o aligner.exe -lsfml-graphics -lsfml-window -lsfml-system
  .\aligner.exe <input_file>

- Windows (Visual Studio / MSVC):
  Use the Visual Studio project or CMake with the SFML prebuilt libraries for MSVC; link the corresponding sfml-*.lib files and ensure the SFML DLLs are alongside the executable or on PATH.

Notes
- On Windows (MinGW), ensure the SFML DLLs are either in the same folder as the executable or available on PATH at runtime.
- If you only need to run tests, Boost.Test can be linked when building `test.cpp` (see the Testing section below).

SFML (required)
- The source files include SFML headers; SFML is therefore required to build and run the program. Link against `sfml-graphics`, `sfml-window`, and `sfml-system` (or the MSVC equivalents) when compiling.
- Example compile flags are shown above in the "Build and run examples" section.

Testing (Boost.Test)
- Unit tests were developed using Boost.Test. To build and run the tests you need Boost libraries installed and an appropriate compiler command. Example (header-only or linked Boost.Test may vary):
  g++ -std=c++17 test.cpp EDistance.cpp -o tests -lboost_unit_test_framework
- Run tests:
  - Linux / macOS: ./tests
  - Windows (PowerShell): .\tests.exe


Results (runs)
| data file     | distance | memory (MB) | time (seconds) | partner time |
|---------------|----------|-------------|----------------|--------------|
| ecoli2500.txt  |   118    |   24.07     |   0.116448     |  0.171335s   |
| ecoli5000.txt  |   160    |   95.76     |   0.436532     |  0.646549s   |
| ecoli10000.txt |   223    |   382.2     |   1.83781      |  2.55383s    |
| ecoli20000.txt |   3135   |   1491      |   8.06143      |  16.8475s    |
| ecoli50000.txt |          |             |    killed      |  killed      |
| ecoli100000.txt|          |             |    killed      |  killed      |

Additional example runs from another machine:
| data file    | distance | time (s) |
|--------------|----------|----------|
| ecoli2500.txt |      118 |    0.171 |
| ecoli5000.txt |      160 |    0.529 |
| ecoli7000.txt |      194 |    0.990 |
| ecoli10000.txt|      223 |    1.972 |
| ecoli20000.txt|     3135 |    7.730 |

Performance estimates
- Time complexity (empirical fit): approx a * N^b where a = 0.000001724 and b = 2.03
- Estimated largest N for 1 day: 7341
- Memory (empirical): approx 4 * N^2 (MB), estimated largest N for 8 GiB: ~400

Files
- `main.cpp` — program entry
- `EDistance.cpp`, `EDistance.hpp` — alignment implementation
- `test.cpp` — tests / experiments